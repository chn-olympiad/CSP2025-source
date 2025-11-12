#include<iostream>
#include<string.h>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;

const int maxn=2.5e6+5,bs=31,p=1e9+7;

int n,q;
char s1[maxn],s2[maxn];
int ed[maxn];
int ln;
ll ans;
int cnt;
int cc;

int hs1[maxn],hs2[maxn],hs3[maxn],hs4[maxn];

map<int,int>ls;

struct nd{
    map<int,int>mp;
};

vector<nd>v;

int id(char a,char b){
    return (a-'a')*26+b-'a';
}

void upd(){
    int p=1;
    for(int i=0;i<ln;i++){
        if(!v[p].mp.count(id(s1[i],s2[i])))
            v[p].mp[id(s1[i],s2[i])]=++cnt;
        p=v[p].mp[id(s1[i],s2[i])];
        cc++;
    }
    ed[p]++;
}

void qry(int st){
    int p=1;
    for(int i=st;i<ln;i++){
        if(!v[p].mp.count(id(s1[i],s2[i])))break;
        p=v[p].mp[id(s1[i],s2[i])];
        if(hs3[i+1]==hs4[i+1])ans+=ed[p];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cnt++;
    v.resize(maxn);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        ln=strlen(s1);
        upd();
    }
    while(q--){
        ans=0;
        cin>>s1>>s2;
        ln=strlen(s1);
        hs1[0]=hs2[0]=hs3[ln]=hs4[ln]=0;
        for(int i=0;i<ln;i++)
            hs1[i]=(1ll*hs1[i-1]*bs+s1[i]-'a')%p,
            hs2[i]=(1ll*hs2[i-1]*bs+s2[i]-'a')%p;
        for(int i=ln-1;i>=0;i--)
            hs3[i]=(1ll*hs3[i+1]*bs+s1[i]-'a')%p,
            hs4[i]=(1ll*hs4[i+1]*bs+s2[i]-'a')%p;
        qry(0);
        for(int i=0;i<ln-1;i++){
            if(hs1[i]!=hs2[i])break;
            qry(i+1);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
