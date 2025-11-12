#include <bits/stdc++.h>
using namespace std;
int t,sum=0,n;
int a[100005],b[100005],c[100005],s[5];
int main()
{
	freopen("club.in","w",stdin);
	freopen("club.out","r",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i]&&a[i]>c[i])
				sum+=a[i];
			else if(b[i]>a[i]&&b[i]>c[i])
				sum+=b[i];
			else
				sum+=c[i];
		}
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}
