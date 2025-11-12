#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
const int N=5*1e5+5;
int a[N],x[N],dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",a+i),x[i]=x[i-1]^a[i];
    for(int i=1;i<=n;i++)mp[k^x[i]]=-1;
    mp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        if(mp[k^x[i]]!=-1)dp[i]=max(dp[i],dp[mp[k^x[i]]]+1);
        mp[x[i]]=i;
    }
    printf("%d\n",dp[n]);
	return 0;
}
