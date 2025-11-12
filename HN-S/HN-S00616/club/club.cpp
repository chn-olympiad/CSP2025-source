#include<bits/stdc++.h>
using namespace std;
int a[100001],b[100001],c[100001];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1; i<=n; i++)cin>>a[i]>>b[i]>>c[i];
		if(n==2)
		{
			cout<<max((a[1]+b[2]),max((a[1]+c[2]),max((b[1]+a[2]),max((b[1]+c[2]),max((c[1]+a[2]),(c[1]+b[2]))))))<<endl;
		}
		else
		{
			int s=0;
			for(int i=1;i<=n;i++)
			{
				s+=max(a[i],max(b[i],c[i]));
			}
			cout<<s<<endl;
		} 
	}
	return 0;
}
