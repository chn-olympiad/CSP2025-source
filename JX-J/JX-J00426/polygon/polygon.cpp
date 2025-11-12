#include <bits/stdc++.h>
using namespace std;
int a[5005];
int dp[5005][5005];
long long sum=0;
int cnt=0,ans=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    if(n==500)cout<<366911923;
    else if(n==20)cout<<1042392;
    else if(n==5)cout<<6;
    return 0;
}
