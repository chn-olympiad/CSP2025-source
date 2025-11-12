#include <bits/stdc++.h>
using namespace std;
#define LL long long

#define N 2007
char s1[N][N],s2[N][N];
char t1[N],t2[N];
bool Ul[N];

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        bool fl=1;
        for(int j=0;j<strlen(s1[i]);j++) if(s1[i][j]!=s2[i][j]) {fl=0;break;}
        if(fl) Ul[i]=1;
    }

    while(q--){
        cin>>t1>>t2;
        if(strlen(t1)!=strlen(t2)) {cout<<0<<'\n';continue;}
        int l=strlen(t1),Ans=0;
        for(int i=1;i<=n;i++){
            int ls=strlen(s1[i]);
            if(Ul[i]||ls>l) continue;
            for(int p=0;p<=l-ls&&t1[p]==t2[p];p++)
                if(t1[p]==s1[i][0]&&t2[p]==s2[i][0]){
                    bool fl=1;
                    for(int j=p+1;j<=p+ls-1;j++) if(t1[j]!=s1[i][j-p]||t2[j]!=s2[i][j-p]) {fl=0;break;}
                    if(!fl) continue;
                    for(int j=p+ls;j<l;j++) if(t1[j]!=t2[j]) {fl=0;break;}
                    Ans+=fl;
                    //if(fl) cout<<i<<' '<<p<<'\n';
                }
        }
        cout<<Ans<<'\n';
    }

    return 0;
}
/*
g++ -Wall replace.cpp -o replace
./replace
*/