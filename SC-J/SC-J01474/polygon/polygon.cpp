#include<bits/stdc++.h>
#define ll long long
#define jmy jiangmuyang
using namespace std;
int a[5005];
ll sum1[5005];
ll sum2[5005];
const ll p=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	ll tot=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		tot+=a[i];
	}
	if(tot>5001) tot=5001;
	sort(a+1,a+n+1);
	ll ans=0;
	ll cnt=0;
	int k;
	for(int i=1;i<=n;i++)
	{
		ans=0;
		for(int j=a[i]+1;j<=tot;j++)
		{
			ans+=sum2[j];
			ans%=p;
		}
		for(int j=tot;j>=1;j--)
		{
			k=min(5001,j+a[i]);
			sum2[k]+=sum2[j]+sum1[j];
			sum2[k]%=p;
		}
		cnt+=ans;
		cnt%=p;
		sum1[a[i]]++;
		sum1[a[i]]%=p;
		
		//for(int j=1;j<=tot;j++)
		//{
		//	if(sum2[j]) cout<<j<<' '<<sum2[j]<<endl;
		//}
	}
	cout<<cnt;
	return 0;
}
