#include<bits/stdc++.h>
#define M 998244353
using namespace std;
int m,n,t,c[505],tot;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='1')tot++;scanf("%d",&c[i+1]);if(c[i+1]==0)t++;
    }if(tot<m){printf("0");return 0;}
    if(tot==n){
        long long ans=1;
        for(int i=1;i<=n-t;i++)ans=(ans*i)%M;
        printf("%lld",ans);return 0;
    }
    return 0;
}
