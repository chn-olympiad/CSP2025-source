#include<bits/stdc++.h>
using namespace std;
int a[100005][10];
int b[100005];
int y3[9]={0,-1,0,1};
int yi=1;
int er;
int san;
int n;
int mmax=-999;
void f(int x2,int y2,int sum)
{
	//cout<<"x:"<<x2<<" y:"<<y2<<endl<<endl;
	sum+=a[x2][y2];
	if(mmax<sum)
	{
		mmax=sum;
		//cout<<"max:"<<mmax<<endl<<endl;
	}
	for(int i=1;i<=3;i++)
	{
		if(y2+y3[i]>=1&&y2+y3[i]<=3&&x2+1<=n)
		{
			if(y2+y3[i]==1&&yi<n/2&&x2+1<=n)
			{
				yi++;
				f(x2+1,y2+y3[i],sum);
				yi--;
			}
			if(y2+y3[i]==2&&er<n/2&&x2+1<=n)
			{
				er++;
				f(x2+1,y2+y3[i],sum);
				er--;
			}
			if(y2+y3[i]==3&&san<n/2&&x2+1<=n)
			{
				san++;
				f(x2+1,y2+y3[i],sum);
				san--;
			}
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		bool flag=true;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		if(n==100000)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=2;j<=3;j++)
				{
					if(a[i][j]!=0)
						flag=false;
				}
			}
			if(flag)
			{
				for(int i=1;i<=n;i++)
				{
					b[i]=a[i][1];
				}
				sort(b,b+n+1);
				int num=0;
				for(int i=n;i>=n/2;i--)
				{
					num+=b[i];
				}
				cout<<num<<endl;
				continue;
			}
		}
		yi=1;
		er=0;
		san=0;
		f(1,1,0);
		yi=0;
		er=1;
		san=0;
		f(1,2,0);
		yi=0;
		er=0;
		san=1;
		f(1,3,0);
		cout<<mmax<<endl;
		mmax=-999;
	}
	return 0;
}
