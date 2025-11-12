#include<bits/stdc++.h> 
using namespace std;
int n,a[100005],usi[100004];
long long sum;
long long ma(int x,int ml,int su,int cu)
{
	if(su>x&&cu>2)sum++;
//	cout<<su<<" "<<ml<<" "<<cu<<" "<<sum<<"\n";
	if(ml==0)return 0;
	int al=0;
	
	for(int j=ml;;j--)
	{
//		cout<<j<<" "<<a[j]<<" "<<cu<<"\n";
		if(j<=0)return 0;
		al=ma(x,j-1,su+a[j],cu+1);
		if(al==0)return 1;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		ma(2*a[i],i-1,a[i],1);
	}
	cout<<sum%998244353;
	return 0;
}
