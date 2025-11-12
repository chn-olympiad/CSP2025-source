#include<bits/stdc++.h>
using namespace std;
	long long a[500001],n,ans=0;
	bool t[500001];
	int p=998244353;
void f(long long ma,int s){
	if(s==0){
		int sum=0;
		for(long long i=n;i>=1;i--)sum+=t[i]*a[i];
		if(sum>ma)
			ans++;
		ans%=p;
		return;
	}
	t[s]=1;
	f(ma,s-1);
	t[s]=0;
	f(ma,s-1);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=3;i<=n;i++)f(a[i],i-1);
	cout<<ans;
	return 0;
}
