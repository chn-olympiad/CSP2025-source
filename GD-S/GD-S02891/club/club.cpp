#include<bits/stdc++.h>
using namespace std;
long long n,t,n1,b[100]={0},sum=0;
struct hhw
{
	long long z,c,m,s;
}a[102000];
bool cmp(hhw x,hhw y)
{
	return x.m>y.m;
}
int main()
{
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout); 
	cin>>t;
	for(long lun=1;lun<=t;lun++)
	{
		cin>>n;
		n1=n/2;
		sum=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(long long i=1;i<=n;i++)
		{
				long long d[100],d1[100];
				cin>>d[1]>>d[2]>>d[3];
				d1[1]=d[1]; d1[2]=d[2]; d1[3]=d[3];
				sort(d+1,d+4);
				a[i].z=d[3]; a[i].c=d[2]; 
				a[i].m=d[3]-d[2]; 
				for(long j=1;j<=3;j++) 	if(d1[j]==a[i].z) a[i].s=j;
		}	
		sort(a+1,a+1+n,cmp);
		for(long i=1;i<=n;i++)
		{
			if(b[a[i].s]<n1)
			{
				b[a[i].s]++;
				sum+=a[i].z;
			}
			else
			{
				sum+=a[i].c;
			}
		}
		cout<<sum<<endl; 
	}
	return 0;
} 
