#include<bits/stdc++.h>
using namespace std;
int a[110005],b[110005],c[110005];
int d[110005];
int e[110005],f[110005],g[110005];
int l[110005];
int h[110005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int ans=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i]>>c[i];
		int s1=0,s2=0,s3=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=b[i]&&a[i]>=c[i])
			{
				d[i]=1;
				s1++;
				f[i]=a[i]-b[i];
				g[i]=a[i]-c[i];
				ans+=a[i];
			}
			else if(b[i]>=a[i]&&b[i]>=c[i])
			{
				d[i]=2;
				s2++;
				e[i]=b[i]-a[i];
				g[i]=b[i]-c[i];
				ans+=b[i];
			}
			else if(c[i]>=a[i]&&c[i]>=b[i])
			{
				d[i]=3;
				s3++;
				f[i]=c[i]-b[i];
				e[i]=c[i]-a[i];
				ans+=c[i];
			}
		}
		if(s1>=n/2)
		{
			int len=0;
			for(int i=1;i<=n;i++)
				if(d[i]==1)
					l[++len]=min(f[i],g[i]);
			sort(l+1,l+len+1,cmp);
			for(int i=n/2+1;i<=len;i++)
			ans-=l[i];
		}
		if(s2>=n/2)
		{
			int len=0;
			for(int i=1;i<=n;i++)
				if(d[i]==2)
					l[++len]=min(e[i],g[i]);
			sort(l+1,l+len+1,cmp);
			for(int i=n/2+1;i<=len;i++)
			ans-=l[i];
		}
		if(s3>=n/2)
		{
			int len=0;
			for(int i=1;i<=n;i++)
				if(d[i]==3)
					l[++len]=min(e[i],f[i]);
			sort(l+1,l+len+1,cmp);
			for(int i=n/2+1;i<=len;i++)
			ans-=l[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
