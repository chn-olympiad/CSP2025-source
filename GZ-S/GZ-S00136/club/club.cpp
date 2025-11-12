//GZ-S00136 遵义市第四中学 安睿峰 
#include <bits/stdc++.h>
using namespace std;
int t,n,ma[100010],cma[100010],h1,h2,h3,a[100010],b[100010],c[100010],ans,a2[100010],b2[100010],c2[100010];
int slove(int num,int z[100010])
{
	sort(z+1,z+num+1);
	for(int i=1;i<=num-n/2;i++)  ans-=z[i];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=h1=h2=h3=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=max(b[i],c[i]))
			{
				ma[i]=a[i];
				if(b[i]>c[i])  cma[i]=b[i];
				else  cma[i]=c[i];
				h1++;a2[h1]=ma[i]-cma[i];
			}
			if(b[i]>=max(a[i],c[i]))
			{
				ma[i]=b[i];
				if(a[i]>c[i])  cma[i]=a[i];
				else  cma[i]=c[i];
				h2++;b2[h2]=ma[i]-cma[i];
			}
			if(c[i]>=max(a[i],b[i]))
			{
				ma[i]=c[i];
				if(a[i]>b[i])  cma[i]=a[i];
				else  cma[i]=b[i];
				h3++;c2[h3]=ma[i]-cma[i];
			}
			ans+=ma[i];
		}
		if(h1>n/2)  slove(h1,a2);
		if(h2>n/2)  slove(h2,b2);
		if(h3>n/2)  slove(h3,c2);
		cout<<ans<<endl;
	}
	return 0;
}
