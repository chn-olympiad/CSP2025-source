#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],s[N],dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,x;
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)s[i]=s[i-1]^a[i];
	for(int i=1;i<=n;i++){
        for(int k=0;k<i;k++){
            dp[i]=max(dp[i],dp[k]+((s[i]^s[k])==x));
        }
	}
	//for(int i=0;i<=n;i++)cout<<dp[i]<<" ";
	printf("%d\n",dp[n]);
	return 0;
}
