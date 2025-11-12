#include<bits/stdc++.h>
using namespace std;
int T,n,a[100010][5],L,c[5],uncom[100010];
struct det
{
	int number1,chamax;
}b[100010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		int maxn=-1,t=0,cnt=1;
		L=0;
		c[1]=0;
		c[2]=0;
		c[3]=0;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=3;k++)
			{
				cin>>a[j][k];
				if(a[j][k]>maxn)
				{
					maxn=a[j][k];
					t=k;
				}
			}
			c[t]++;
			L+=maxn;
			b[j].number1=t;
			maxn=-1;
			if(t==1) b[j].chamax=min(abs(a[j][1]-a[j][2]),abs(a[j][1]-a[j][3]));
			if(t==2) b[j].chamax=min(abs(a[j][2]-a[j][1]),abs(a[j][2]-a[j][3]));
			if(t==3) b[j].chamax=min(abs(a[j][3]-a[j][1]),abs(a[j][3]-a[j][2]));
		}
		for(int j=1;j<=3;j++)
		{
			if(c[j]>n/2)
			{
				for(int k=1;k<=n;k++)
				{
					if(b[k].number1==j)
					{
						uncom[cnt]=b[k].chamax;
						cnt++;
					}
				}
				sort(uncom+1,uncom+1+cnt-1);
				for(int k=1;k<=c[j]-n/2;k++)
				L-=uncom[k];
			}
		}
		for(int j=1;j<=cnt;j++)
		{
			uncom[j]=0;
		}
		cout<<L<<endl;
	}
}
