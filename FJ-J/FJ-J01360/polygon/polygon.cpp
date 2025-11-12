#include<bits/stdc++.h>
using namespace std;
int n,a[5001];long long ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=7;i<(1<<n);i++){
		int m=0,maxw=0,cnt=0;
		for(long long j=0;j<n;j++)
		{
			if(i&(1<<j)){
				m++;
				maxw=max(maxw,a[j]);
				cnt+=a[j];
			}
		}
		if(m>=3&&cnt>2*maxw){
			ans++;
			ans%=998244353;
		}
	}
	cout<<ans;
	return 0;
}