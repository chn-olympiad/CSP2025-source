#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
const ll B=1003;
ll n,m;
map<ll,ll> mp;
char s[5000001],op[5000001];
ll hax[5000001],hay[5000001];
ll pows[5000001];
struct node{
    vector<char> x,y;
    ll hx=0,hy=0;
    ll siz,lops,pre;
}a[200001];
bool cmp(node x,node y){
    return x.lops>y.lops;
}
struct sdd{
    ll st,hasxx,hasyy,siz;
};
vector<sdd> g[5000001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >>n >>m;
    pows[0]=1;
    for(int i=1;i<=5000000;i++) pows[i]=pows[i-1]*B%mod;
    for(int i=1;i<=n;i++){
        cin >>s;
        a[i].siz=strlen(s);
        for(int j=0;j<a[i].siz;j++) a[i].x.push_back(s[j]),a[i].hx=(a[i].hx*B%mod)+s[j]-'a';
        cin >>s;
        ll st=a[i].siz,ed=-1;
        for(int j=0;j<a[i].siz;j++){
            if(s[j]!=a[i].x[j]){
                if(st==a[i].siz) st=j;
                ed=j;
            }
        }
        for(int j=0;j<a[i].siz;j++) a[i].y.push_back(s[j]),a[i].hy=(a[i].hy*B%mod)+s[j]-'a';
        if(st<=ed) a[i].lops=ed-st+1;
        else a[i].lops=-1;
        if(st<=ed) a[i].pre=st;
        if(a[i].lops!=-1)g[a[i].lops].push_back({a[i].pre,a[i].hx%mod,a[i].hy%mod,a[i].siz});
    }
    for(int opk=1;opk<=m;opk++){
        cin >>s;
        cin >>op;
        ll len=strlen(s);
        ll st=len,ed=-1;
        for(int i=0;i<len;i++){
            hax[i+1]=(hax[i]*B)%mod;
            hax[i+1]+=s[i]-'a';
            hax[i+1]%=mod;
            hay[i+1]=hay[i]*B%mod;
            hay[i+1]+=op[i]-'a';
            hay[i+1]%=mod;
            //if(opk==455 && hax[i+1]<0) cout <<hax[i+1] <<"!";
        }

        //cout <<hax[1];
        for(int i=0;i<len;i++){
            if(s[i]!=op[i]){
                if(st==len) st=i;
                ed=i;
            }
        }
        ll ans=0;
        //if(opk==455) cout <<st <<" " <<ed <<'\n';
       // for(int i=st;i<ed;i++) hax=(hax*B%mod)+s[i]-'a',hay=(hay*B%mod)+op[i]-'a';
        for(auto to:g[ed-st+1]){
            ll pred=st-to.st+1;
            ll lstd=pred+to.siz-1;
            //cout <<to.st <<" " <<st <<" ";
            if(pred>=1 && lstd<=len){
                //if(opk==455 && (hax[lstd]-((hax[pred-1]*pows[lstd-pred+1])%mod)+mod)%mod<0) cout <<lstd <<" " <<hax[lstd] <<" " <<((hax[pred-1]*pows[lstd-pred+1])%mod) <<'\n';
                //if(opk==455) cout <<( <<" ";
                if((hax[lstd]-((hax[pred-1]*pows[lstd-pred+1])%mod)+mod)%mod==to.hasxx && (hay[lstd]-((hay[pred-1]*pows[lstd-pred+1])%mod)+mod)%mod==to.hasyy) ans++;
            }
        }
        //(hax[lstd]-((hax[pred]*pows[lstd-pred+1])%mod)+mod)%mod==to.hasxx && (hay[lstd]-((hay[pred]*pows[lstd-pred+1])%mod)+mod)%mod==to.hasyy
        cout <<ans <<'\n';
    }
    return 0;
}
