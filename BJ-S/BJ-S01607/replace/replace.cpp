#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,s,e) for(int i=s;i<=e;i++)
#define dfr(i,s,e) for(int i=s;i>=e;i--)
int son[5000010][26],fail[5000010];
int ct=1;
int bel[5000010],dy[5000010];
string s1[200010],s2[200010];
set<int> st[5000010];
void ins(string s,int id){
    int p=1;
    for(auto x:s){
        if(!son[p][x-'a'])son[p][x-'a']=++ct;
        p=son[p][x-'a'];
    }
    if(bel[p])
        dy[id]=bel[p];
    else bel[p]=id;
}
vector<int> mp[5000010];
void build(){
    fr(i,1,ct)mp[i].clear();
    queue<int> q;
    fr(i,0,25){
        if(son[1][i]){
            fail[son[1][i]]=1;
            mp[1].push_back(son[1][i]);
            q.push(son[1][i]);
        }
        else son[1][i]=1;
    }
    while(!q.empty()){
        int p=q.front();q.pop();
        //cout << p << endl;
        fr(i,0,25){
            if(son[p][i]){
                q.push(son[p][i]);
                fail[son[p][i]]=son[fail[p]][i];
                mp[fail[son[p][i]]].push_back(son[p][i]);
            }
            else{
                son[p][i]=son[fail[p]][i];
            }
        }
    }
   // cout << son[8][2] << endl;
    //for(auto x:mp[10])cout << x<< " ";
    //cout << endl;
}
const int mod=1e9+3;
int h[5000010];
int hs[200010];
int pw[5000010],ipw[5000010];
int qpow(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
inline bool ck(int l,int r,int hs){
    return ((h[r]-(h[l-1]*pw[r-l+1]%mod)+mod)%mod)==hs;
}
int ans=0;
void dfs(int p,int lpp){
    for(auto x:mp[p]){
        dfs(x,lpp);
        if(st[x].size()>st[p].size())swap(st[x],st[p]);
        for(auto y:st[x])st[p].insert(y);
    }
    if(bel[p]){
        for(auto j:st[p]){
            int lp=j-s1[bel[p]].size()+1;
            if(lp>lpp)continue;
            if(ck(lp,j,hs[bel[p]]))ans++;
        }
    }
}
vector<pair<pair<int,int>,int> > mpp[10000010];
//                                   10000000
int bt[5000010];
int lowbit(int p){
return p&(-p);}
void upd(int p,int v){
    p++;
    while(p<=5000001){
        bt[p]+=v;
        p+=lowbit(p);
    }
}
int get1(int p){
    p++;
    int res=0;
    while(p){
        res+=bt[p];
        p-=lowbit(p);
    }
    return res;
}
int Ans[200010];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,q;
    cin >> n >> q;
    pw[0]=1;
    fr(i,1,5000000)pw[i]=(pw[i-1]*26)%mod;
    ipw[0]=1;
    ipw[1]=qpow(26,mod-2);
    fr(i,2,5000000)ipw[i]=ipw[i-1]*ipw[1]%mod;
    int cts=0;
    fr(i,1,n){
        cin >> s1[i] >> s2[i];
        cts+=s1[i].size();
        ins(s1[i],i);
        for(auto x:s2[i]){
            hs[i]=(hs[i]*26%mod+x-'a')%mod;
        }

    }
    if(q>100||(cts>=1e5&&q!=1)){
        fr(i,1,n){
            int p1,p2,lnd,rnd;
            s1[i]=" "+s1[i],s2[i]=" "+s2[i];
            fr(j,1,s1[i].size()-1){
                if(s1[i][j]=='b'){
                    p1=j,lnd=j-1,rnd=s1[i].size()-1-j;
                    break;
                }
            }
            fr(j,1,s2[i].size()-1)
                if(s2[i][j]=='b')p2=j;
            int dx=p2-p1+5000000;
            mpp[dx].push_back({{lnd,rnd},0});
        }
        fr(i,1,q){
            string t1,t2;
            cin >> t1 >> t2;
            t1=" "+t1,t2=" "+t2;
            int p1,p2,lnd,rnd;
            fr(j,1,t1.size()-1){
                if(t1[j]=='b'){
                    p1=j,lnd=j-1,rnd=t1.size()-1-j;
                    break;
                }
            }
            fr(j,1,t2.size()-1)
                if(t2[j]=='b')p2=j;
            int dx=p2-p1+5000000;
            mpp[dx].push_back({{lnd,rnd},i});
        }
       // cout << 123 << endl;
        fr(i,0,10000000){
            if(mpp[i].empty())continue;
            sort(mpp[i].begin(),mpp[i].end());
            for(auto x:mpp[i]){
                int v1=x.first.first,v2=x.first.second,id=x.second;
                if(id==0){
                    upd(v2,1);
                }
                else Ans[id]=get1(v2);
            }
for(auto x:mpp[i]){
                int v1=x.first.first,v2=x.first.second,id=x.second;
                if(id==0){
                    upd(v2,-1);
                }
            }

        }
        fr(i,1,q)cout << Ans[i] << endl;
        return 0;
    }
    //cout << son[1][23] << endl;
    build();
    //cout << fail[5] << endl;
    //cout << 123 << endl;
    while(q--){
        fr(i,1,ct)st[i].clear();
        string t1,t2;
        cin >> t1 >> t2;
        t1=" "+t1,t2=" "+t2;
        int lpp=0x3f3f3f3f,rpp=-1;
        fr(i,1,t2.size()){
            h[i]=(h[i-1]*26%mod+t2[i]-'a')%mod;
            if(t1[i]!=t2[i])lpp=min(lpp,i),rpp=max(rpp,i);
        }
      //  cout << lpp << " " << rpp << endl;
        int p=1;
        fr(i,1,t1.size()-1){
            p=son[p][t1[i]-'a'];
            if(i>=rpp){
                st[p].insert(i);
            }
        }
       // cout << fail[6] << endl;
        //cout << "ed" << endl;
        ans=0;
        dfs(1,lpp);
        cout << ans <<endl;
    }
    return 0;
}
