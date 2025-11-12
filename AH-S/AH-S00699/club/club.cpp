#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005],b[100005],c[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int s=0,ren=0;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j]>>b[j]>>c[j];
			for(int z=1;z<j;z++)
			{
				if(a[j]>a[z]) swap(a[j],a[z]);
				if(b[j]>b[z]) swap(b[j],b[z]);
				if(c[j]>c[z]) swap(c[j],c[z]);
			}
		}
		for(int j=1;j<=3*n;j++)
		{
			if(ren>=n) break;
			if(a[n/2]==a[n/2+1]&&a[n/2]==a[n/2+2])
				for(int z=1;z<=n;z++)
					a[z]=0;
			if(b[n/2]==b[n/2+1]&&b[n/2]==b[n/2+2])
				for(int z=1;z<=n;z++)
					b[z]=0;
			if(c[n/2]==c[n/2+1]&&c[n/2]==c[n/2+2])
				for(int z=1;z<=n;z++)
					c[z]=0;
			if(a[1]>=b[1]&&a[1]>=c[1])
			{
				s+=a[1];
				ren++;
				a[1]=0;
				for(int z=1;z<=n;z++)
				{
					int t=a[z];
					a[z]=a[z+1];
					a[z+1]=t;
				}
			}
			else if(b[1]>=a[1]&&b[1]>=c[1])
			{
				s+=b[1];
				ren++;
				b[1]=0;
				for(int z=1;z<=n;z++)
				{
					int t=b[z];
					b[z]=b[z+1];
					b[z+1]=t;
				}
			}
			else if(c[1]>=b[1]&&c[1]>=a[1])
			{
				s+=c[1];
				ren++;
				c[1]=0;
				for(int z=1;z<=n;z++)
			{
					int t=c[z];
					c[z]=c[z+1];
				c[z+1]=t;
				}
			}
		}
		cout<<s;
	}
	return 0;
}
