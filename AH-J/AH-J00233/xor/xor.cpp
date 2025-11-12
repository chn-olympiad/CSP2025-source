#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500050],dp[500050];
bool f(int l,int r){
	int sum=a[l];
	for(int i=l+1;i<=r;i++)sum=sum^a[i];
	if(sum==k)return 1;
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){//以i為結尾
		dp[i]=dp[i-1];
		for(int j=1;j<=i;j++)//以j為開頭
			if(f(j,i))dp[i]=max(dp[i],dp[j-1]+1);
	}
	cout<<dp[n];
	return 0;
}
