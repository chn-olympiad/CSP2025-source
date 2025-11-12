/*
Author: Shunpower in CSP-S2025

我感到 soul cries
灵魂被 sold out
但不会懈怠 腐烂被嗅到
炙热的心才是最好解药
2025AMBITION with my freestyle
*/
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define fr1(i,a,b) for(int i=(a);i<=(b);i++)
#define fr2(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
using namespace std;
const int N=2e5+10;
const int M=5e6+10;
int n,q;
#define pss pair<string,string>
pss s[N];
string t1,t2;
string difsame[N];
string suf;
const int base=293;
const int mod1=998244353,mod2=200707201;
pair<pii,pii> hsh[N];
pii g[M];
int tot;
map <pair<pii,pii>,int> c;
unordered_map <ll,int> e[N];
struct Trie{
    int tot;
    int ch[M][26];
    int sum[M];
    bool vis[M];
    void insert(int &p,string s){
        if(!p) tot++,p=tot;
        int np=p;
        for(auto i:s){
            if(!ch[np][i-'a']) tot++,ch[np][i-'a']=tot;
            np=ch[np][i-'a'];
        }
        vis[np]=1;
        sum[np]++;
    }
    void dfs(int r,int x,int h1,int h2){
        if(!x) return;
        e[r][1ll*h1*mod2+h2]=sum[x];
        fr1(i,0,25){
            if(ch[x][i]){
                sum[ch[x][i]]+=sum[x];
                dfs(r,ch[x][i],(1ll*h1*base+('a'+i))%mod1,(1ll*h2*base+('a'+i))%mod2);
            }
        }
    }
} T;
int r[N];
#define f(x) (1ll*x.fi*mod2+x.se)
// bool isprefix(string &s,string &t){
//     if(s.length()>t.length()) return 0;
//     fr1(i,0,(int)s.length()-1){
//         if(s[i]!=t[i]) return 0;
//     }
//     return 1;
// }
#define shun cute
int main(){
#ifdef shun
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin>>n>>q;
    fr1(i,1,n){
        cin>>s[i].fi>>s[i].se;
        difsame[i]="";
        while(!s[i].fi.empty()){
            if(s[i].fi.back()!=s[i].se.back()) break;
            difsame[i]+=s[i].fi.back();
            s[i].fi.pop_back();
            s[i].se.pop_back();
        }
        if(!difsame[i].empty()) reverse(difsame[i].begin(),difsame[i].end());
        if(!s[i].fi.empty()) reverse(s[i].fi.begin(),s[i].fi.end());
        if(!s[i].se.empty()) reverse(s[i].se.begin(),s[i].se.end());
        int h11=0,h12=0,h21=0,h22=0;
        for(auto j:s[i].fi){
            h11=(1ll*h11*base+j)%mod1;
            h12=(1ll*h12*base+j)%mod2;
        }
        for(auto j:s[i].se){
            h21=(1ll*h21*base+j)%mod1;
            h22=(1ll*h22*base+j)%mod2;
        }
        hsh[i]=mp(mp(h11,h12),mp(h21,h22));
        c[hsh[i]]++;
    }
    for(auto &i:c){
        tot++;
        i.se=tot;
    }
    fr1(i,1,n){
        int rt=c[hsh[i]];
        // cout<<"??"<<rt<<' '<<difsame[i]<<endl;
        T.insert(r[rt],difsame[i]);
    }
    fr1(i,1,tot){
        T.dfs(i,r[i],0,0);
        // cout<<i<<":"<<endl;
        // for(auto j:e[i]) cout<<j.fi.fi<<' '<<j.fi.se<<endl;
    }
    while(q--){
        cin>>t1>>t2;
        if(t1.size()!=t2.size()){
            cout<<"0\n";
            continue;
        }
        int lastdif=0,firstdif=t1.size();
        fr1(i,0,(int)t1.size()-1){
            if(t1[i]!=t2[i]){
                lastdif=i;
                firstdif=min(firstdif,i);
            }
        }
        string t="";
        fr1(i,lastdif+1,t1.size()-1) t+=t1[i];
        {
            int h1=0,h2=0;
            g[0]=mp(0,0);
            fr1(i,lastdif+1,(int)t1.size()-1){
                char c=t1[i];
                h1=(1ll*h1*base+c)%mod1,h2=(1ll*h2*base+c)%mod2;
                g[i-lastdif]=mp(h1,h2);
            }
        }
        ll res=0;
        int h11=0,h12=0,h21=0,h22=0;
        fr2(j,lastdif,firstdif+1){
            char c1=t1[j],c2=t2[j];
            h11=(1ll*h11*base+c1)%mod1,h12=(1ll*h12*base+c1)%mod2;
            h21=(1ll*h21*base+c2)%mod1,h22=(1ll*h22*base+c2)%mod2;
        }
        fr2(j,firstdif,0){
            char c1=t1[j],c2=t2[j];
            h11=(1ll*h11*base+c1)%mod1,h12=(1ll*h12*base+c1)%mod2;
            h21=(1ll*h21*base+c2)%mod1,h22=(1ll*h22*base+c2)%mod2;
            pair<pii,pii> h=mp(mp(h11,h12),mp(h21,h22));
            if(!c.count(h)) continue;
            int rt=c[h];
            // fr1(i,1,n){
            //     if(c[hsh[i]]==rt&&isprefix(difsame[i],t)){
            //         res++;
            //     }
            // }
            int l=lastdif+1,r=(int)t1.size()-1,ans=lastdif;
            while(l<=r){
                int mid=(l+r>>1);
                if(e[rt].count(f(g[mid-lastdif]))) ans=mid,l=mid+1;
                else r=mid-1; 
            }
            pii fn=g[ans-lastdif];
            // cout<<"??"<<fn.fi<<' '<<fn.se<<endl;
            res+=e[rt][f(fn)];
            // cout<<rt<<"!"<<j<<":"<<res<<' '<<ans-lastdif<<endl;
        }
        cout<<res<<'\n';
    }
    // cerr<<clock()<<endl;
    return 0;
}
/*
注意只考到18:30
last 15min, NOI Linux for big samples
never stop thinking
Stage 9
冷静。冷静。冷静。

g++ -O2 -std=c++14 a.cpp -o a
*/