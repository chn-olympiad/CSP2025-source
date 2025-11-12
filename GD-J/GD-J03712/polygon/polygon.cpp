#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
//int sum[5005];
bool vis[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		//sum[i]=sum[i-1]+a[i];
	}
	int num=0;
	int maxx=-9999999;
	int ans=0;
	int b=maxx;
	for(int i=0;i<(1<<n);i++){
		num=0;
		maxx=-9999999;
		b=maxx;
		for(int j=0;j<i;j++){
			if(i&(1<<j)){
				num+=a[j];
				maxx=max(maxx,a[j]);
			}
		}
		if(num>2*maxx&&b!=maxx){
			ans++;
		}
	}
	cout<<ans%998244353;
	return 0;
}
