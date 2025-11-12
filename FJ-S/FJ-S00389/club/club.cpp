#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int t,f[N][N],l[N][4],sum;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int n;
		sum=0;
		memset(f,0,sizeof(f));
		memset(l,0,sizeof(l));
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>l[i][1]>>l[i][2]>>l[i][3];
		if(n==2)
		{
			int a[7];
			a[1]=l[1][1]+l[2][2];
			a[2]=l[1][1]+l[2][3];
			a[3]=l[1][2]+l[2][1];
			a[4]=l[1][2]+l[2][3];
			a[5]=l[1][3]+l[2][1];
			a[6]=l[1][3]+l[2][2];
			sort(a+1,a+7);
			cout<<a[6];
		 } 
		else 
		{
			for(int k=1;k<=n;k++)
			{
				for(int i=1;i<=3;i++)
					for(int j=1;j<=n/2;j++)
						f[i][j]=max(f[i][j-1]+l[k][i],f[i][j]);
			
			}
			for(int i=0;i<=n/2;i++)
			{	
				for(int j=0;j<=n/2&&j<=n-i;j++)
					for(int p=0;p<=n/2&&p<=n-i-j;p++)
						if(i+j+t==n)
							sum=max((f[1][i]+f[2][j]+f[3][p]),sum);
			}
			cout<<sum<<endl;
		}
			
	}
	return 0;
}

