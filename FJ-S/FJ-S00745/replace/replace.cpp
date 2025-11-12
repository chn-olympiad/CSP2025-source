#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define forto(i,a,b) for(int i(a),_##i(b);i<=_##i;i++)
#define forbk(i,a,b) for(int i(a),_##i(b);i>=_##i;i--)
#define forv(i,a) for(int i(0),_##i(a);i<_##i;i++)
#define il inline
#define mkp make_pair
#define eb emplace_back
using namespace std;

const int N=200005,P1=1000000919,P2=1000000871,B1=10000019,B2=10000079;
struct ACAM{
    int *ch[27],*cnt,*fail,tot=0;
    il void init(int mx){
        tot=0;
        forv(i,27)ch[i]=new int[mx]();
        cnt=new int[mx]();
        fail=new int[mx]();
    }
    il void push(string &s){
        int x=0;
        forv(i,s.size()){
            if(!ch[s[i]-'a'][x])ch[s[i]-'a'][x]=++tot;
            x=ch[s[i]-'a'][x];
        }
        cnt[x]++;
    }
    il void build(){
        queue<int>q;
        forv(i,27)if(ch[i][0])q.push(ch[i][0]);
        while(!q.empty()){
            int x=q.front();q.pop();
            cnt[x]+=cnt[fail[x]];
            forv(c,27){
                if(ch[c][x])fail[ch[c][x]]=ch[c][fail[x]],q.push(ch[c][x]);
                else ch[c][x]=ch[c][fail[x]];
            }
        }
    }
    il int ask(string &s){
        int x=0,res=0;
        forv(i,s.size()){
            x=ch[s[i]-'a'][x];
            res+=cnt[x];
        }
        return res;
    }
}acam[N];
int n,q;
string s1[N],s2[N];
int tot=0,id[N],len[N];
map<pii,int>mp;

signed main(){
    freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;
    forto(i,1,n){
        cin>>s1[i]>>s2[i];
        int p=-1,h1=0,h2=0;
        forv(j,s1[i].size()){
            if(s1[i][j]!=s2[i][j]){
                if(p==-1)p=j;
                h1=(1ll*h1*B1+j-p)%P1,h1=(1ll*h1*B1+s1[i][j])%P1,h1=(1ll*h1*B1+s2[i][j])%P1;
                h2=(1ll*h2*B2+j-p)%P2,h2=(1ll*h2*B2+s1[i][j])%P2,h2=(1ll*h2*B2+s2[i][j])%P2;
            }
        }
        if(mp.count({h1,h2}))id[i]=mp[{h1,h2}];
        else mp[{h1,h2}]=id[i]=++tot;
        len[id[i]]+=s1[i].size()+1;
        // cerr<<h1<<' '<<h2<<'\n';
    }
    forto(i,1,tot)acam[i].init(len[i]+5);
    string tmp;
    forto(i,1,n){
        tmp=s2[i];
        forv(j,s1[i].size())if(s1[i][j]!=s2[i][j])tmp[j]='z'+1;
        acam[id[i]].push(tmp);
        // cerr<<id[i]<<' '<<tmp<<'\n';
    }
    forto(i,1,tot)acam[i].build();
    string t1,t2;
    while(q--){
        cin>>t1>>t2;
        if(t1.size()!=t2.size()){
            cout<<"0\n";
            continue;
        }
        int p=-1,h1=0,h2=0;
        forv(j,t1.size()){
            if(t1[j]!=t2[j]){
                if(p==-1)p=j;
                h1=(1ll*h1*B1+j-p)%P1,h1=(1ll*h1*B1+t1[j])%P1,h1=(1ll*h1*B1+t2[j])%P1;
                h2=(1ll*h2*B2+j-p)%P2,h2=(1ll*h2*B2+t1[j])%P2,h2=(1ll*h2*B2+t2[j])%P2;
            }
        }
        if(!mp.count({h1,h2})){
            cout<<"0\n";
            continue;
        }
        int t=mp[{h1,h2}];
        tmp=t2;
        forv(j,t1.size())if(t1[j]!=t2[j])tmp[j]='z'+1;
        // cerr<<t<<' '<<tmp<<'\n';
        cout<<acam[t].ask(tmp)<<'\n';
    }
    return 0;
}