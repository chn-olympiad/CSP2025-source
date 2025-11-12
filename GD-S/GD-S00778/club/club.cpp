#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long a[N],b[N],c[N],l;
long long t,n,k[10],sum=0,maxx=0,maxx2,sum2=0;
bool aa=false,bb=false,cc=false;
bool caa=false,cbb=false,ccc=false;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		aa=false;
		bb=false;
		cc=false;
		caa=false;
		cbb=false;
		ccc=false;
		sum=0;
		sum2=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
			k[i]=a[i];
			k[i+1]=b[i];
			k[i+2]=c[i];
			maxx=0;
			maxx2=0;
			for(int j=i;j<=i+3;j++)
			{
				maxx=max(maxx,k[j]);
			}
			maxx2=maxx;
			l=maxx;
			//第一种情况：找最大值 
			if(aa==true && bb==true && cc==true)
			{
				sum+=maxx;
			}
			if(maxx==a[i] && aa==false)
			{
				aa=true;
				sum+=maxx;
			}
			else if(maxx==b[i] && bb==false)
			{
				bb=true;
				sum+=maxx;
			}
			else if(maxx==c[i] && cc==false)
			{
				cc=true;
				sum+=maxx; 
			}
			if(aa==true && bb==true && cc==true)
			{
				sum+=maxx;
			}
			//第二种情况：找第二大的值
			if(caa==true && cbb==true && ccc==true)
			{
				sum2+=maxx2;
			}
			for(int j=i;j<=i+3;j++)
			{
				if(k[j]>l && k[j]<maxx2)
				{
					maxx2=k[j];
				}
			}
			if(maxx2==a[i] && caa==false)
			{
				caa=true;
				sum2+=maxx;
			}
			else if(maxx2==b[i] && cbb==false)
			{
				cbb=true;
				sum2+=maxx;
			}
			else if(maxx2==c[i] && ccc==false)
			{
				ccc=true;
				sum2+=maxx; 
			} 
			if(caa==true && cbb==true && ccc==true)
			{
				sum2+=maxx2;
			}
		}
		for(int i=1;i<=n;i++)
		{
			a[i]=0;
			b[i]=0;
			c[i]=0;
			k[i]=0;
		}
		printf("%lld\n",max(sum2,sum));
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
