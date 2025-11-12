#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int dp[500005],a[500005],x[500005],vis[1048581];
int yh(int a,int b){
	int ans=0,sum=1048576;
	while(a||b){
		if(a/sum!=b/sum){
			ans+=sum;
		}
		a%=sum;b%=sum;
		sum/=2;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int n,k;cin>>n>>k;
	int b[500005];dp[0]=0;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		a[i]=yh(x[i],a[i-1]);
		vis[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		b[i]=a[n-i+1];
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		int y=yh(a[i],k);
		//cout<<y<<" ";
		if(find(a,a+i,y)!=a+i){
			int j=find(b+n-i+2,b+n+1,y)-b;
			j=n-j+1;//cout<<j<<" ";
			dp[i]=max(dp[i],dp[j]+1);
			//cout<<dp[i]<<"\n";
		}
	}
	cout<<dp[n];
	return 0;
}/*
for(int j=i-1;j>=0;j--){
if(yh(a[i],a[j])==k){
dp[i]=max(dp[i],dp[j]+1);
break;
}
}
*/