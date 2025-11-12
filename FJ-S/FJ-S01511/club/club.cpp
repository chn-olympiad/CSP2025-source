#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long n;
struct student
{
	long long df,ds,dfi,dsi;
}a[123456];
struct e
{
	long long z;
	long long id;
};
bool cmp(e x,e y)
{
	return x.z<y.z;
}
e o[4][111111];
long long cnt[4];
long long slov(int x)
{
	long long mi=214748360000;
	long long idd=0;
	for(int i=1;i<cnt[x];i++)
	{
		long long u=o[x][i].z-o[x][i].id;
		if(mi>u)
		{
			mi=u;
			idd=i;
		}
	}
	return idd;
}
void init()
{
	for(int i=1;i<=n/2+1;i++)
	{
		a[i].df=0;
		a[i].ds=0;
		a[i].dfi=0;
		a[i].dsi=0;
		o[1][i].z=0;
		o[1][i].id=0;
		o[2][i].z=0;
		o[2][i].id=0;  
		o[3][i].z=0;
		o[3][i].id=0;
}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	
	while(t--){

	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		e q[4];
		q[1].id=1;
		q[2].id=2;
		q[3].id=3;
		cin>>q[1].z>>q[2].z>>q[3].z;
		sort(q+1,q+4,cmp);
		a[i].df=q[3].z-q[1].z;
		a[i].ds=q[2].z-q[1].z;
		a[i].dfi=q[3].id;
		a[i].dsi=q[2].id;
		sum+=q[1].z;
	}
	long long q[4];
	q[1]=0;q[2]=0;q[3]=0;
	cnt[1]=1;cnt[2]=1;cnt[3]=1;
	bool aaa=0;
	for(int i=n;i>=1;i--)
	{
		if(q[a[i].dfi]>=n/2)
		{
			aaa=1;
			int pd=slov(a[i].dfi);
			 if(a[i].df-a[i].ds>o[a[i].dfi][pd].z-o[a[i].dfi][pd].id)
			{
					sum+=a[i].df;
					sum-=o[a[i].dfi][pd].z;
					sum+=o[a[i].dfi][pd].id;
					o[a[i].dfi][pd].z=a[i].df;
					o[a[i].dfi][pd].id=a[i].ds;
			}
			else
			{
				sum+=a[i].ds;
				
			}
		}
		else if(aaa==1)
		{
			sum+=a[i].df;
		}
		else
		{
			q[a[i].dfi]++;
			o[a[i].dfi][cnt[a[i].dfi]].z=a[i].df;
			o[a[i].dfi][cnt[a[i].dfi]++].id=a[i].ds;
			
			sum+=a[i].df;
		}
	}
	cout<<sum<<'\n';
	init();
	}
return 0;
	}

