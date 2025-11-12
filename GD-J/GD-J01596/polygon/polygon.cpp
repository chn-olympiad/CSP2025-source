#include<bits/stdc++.h>
using namespace std;
int n,a[5005],s[25000005],t=3,ans,la;
int main()
{
	freopen("polygon4.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
//	cout<<endl;
	s[1]=a[1];
	s[2]=a[2];
	s[3]=a[1]+a[2];
	for(int i=3;i<=n;i++)
	{
		for(int j=1,e=t;j<=e;j++)
		{
			s[++t]=a[i]+s[j];
		}
		s[++t]=a[i];
		sort(s+1,s+t+1);
//		for(int j=1;j<=t;j++)cout<<s[j]<<" ";
//		cout<<endl;
		int l=1,r=t,mi=0,q=t+1;
		while(l<=r)
		{
			mi=(l+r)>>1;
			if(s[mi]>a[i]*2)
			{
				r=mi-1;
				q=mi;
			}
			else l=mi+1;
		}
		if(a[i]==a[i+1])continue;
		ans+=t-q+1;
//		cout<<t-q+1<<endl;
	}
	cout<<ans;
}

