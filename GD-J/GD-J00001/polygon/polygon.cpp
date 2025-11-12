#include<bits/stdc++.h>
using namespace std;
long long ok[25000010];
int v=0;
int ans=0;
int mod=998244353;
long long cnt[25000010];
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	ok[0]=1;
	for(int i=1;i<=n;i++)v+=a[i];
	for(int i=1;i<n;i++){
		for(int j=v;j>=a[i];j--)ok[j]+=ok[j-a[i]],ok[j]%=mod;
		for(int j=v;j>=0;j--)cnt[j]=cnt[j+1]+ok[j],cnt[j]%=mod;
		ans+=cnt[a[i+1]+1];
		ans%=mod;
	}
	cout<<ans%mod;
}
