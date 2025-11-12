#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010],c[100010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,ans=0;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		ans=0;
		cin>>n;
		for(int j=1;j<=n;j++) 
			cin>>a[j]>>b[j]>>c[j];
		sort(a+1,a+1+n);
		for(int j=n;j>n/2;j--)
			ans+=a[j];
		cout<<ans; 
	}
	return 0;
}

