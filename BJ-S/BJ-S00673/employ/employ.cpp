#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m,r[514],su,tong[514];
long long ans=1;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin>>s;
    for(int i=1;i<=n;i++){
        scanf("%d",r+i);
        if(r[i]) su++;
        tong[r[i]]++;
    }
    int ssu=su,te=1;
    while(ssu>m&&te<=tong[0]){
        ssu-=tong[te++];
        su++;
    }
    if(su<m){
        printf("0");
        return 0;
    }
    for(long long i=1;i<=su;i++){
        ans*=i;
        if(ans>mod) ans%=mod;
    }
    printf("%lld",ans);
    return 0;
}
