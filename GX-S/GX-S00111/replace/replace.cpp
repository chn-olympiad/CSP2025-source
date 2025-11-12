#include<bits/stdc++.h>
using namespace std;
#define p1 998244353
#define p2 1000000007
#define b1 131
#define b2 13331
#define pii pair<int,int>
#define se second
#define fi first
pii gethash(string &s){
    int h1=0,h2=0;
    for(int i=1;i<=s.size();i++)
        h1=(1ll*h1*b1+s[i-1])%p1;
    for(int i=1;i<=s.size();i++)
        h2=(1ll*h2*b2+s[i-1])%p2;
    return {h1,h2};
}
int pw1[10010],pw2[10010];
void init(){
    pw1[0]=pw2[0]=1;
    for(int i=1;i<=10000;i++){
        pw1[i]=1ll*pw1[i-1]*b1%p1;
        pw2[i]=1ll*pw2[i-1]*b2%p2;
    }
}
struct HS{
    pii hs[10010];

    void geths(string &s){
        hs[0].fi=hs[0].se=0;
        for(int i=1;i<=s.size();i++)
            hs[i].fi=(1ll*hs[i-1].fi*b1+s[i-1])%p1;
        for(int i=1;i<=s.size();i++)
            hs[i].se=(1ll*hs[i-1].se*b2+s[i-1])%p2;
    }
    
    pii getlr(int l,int r){
        int len =r-l+1;
        return {(1ll*hs[r].fi+p1-1ll*hs[l-1].fi*pw1[len]%p1)%p1,(1ll*hs[r].se+p2-1ll*hs[l-1].se*pw2[len]%p2)%p2};
    }
}a,b;
int n,q;
pii s[10010][2];
int sz[10010];

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    init();
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        s[i][0]=gethash(s1);
        s[i][1]=gethash(s2);
        sz[i]=s1.size();
    }
    while(q--){
        string t1,t2;
        cin>>t1>>t2;
        a.geths(t1);
        b.geths(t2);
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=t1.size()-sz[i]+1;j++)
                if(a.getlr(j,j+sz[i]-1)==s[i][0]&&b.getlr(j,j+sz[i]-1)==s[i][1])
                    ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}