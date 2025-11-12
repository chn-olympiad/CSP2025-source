#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n,a[N][4],juq3=0,juq2=0,d1[N],cz[N],jsq=0;
		cin>>n;
	
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			jsq+=a[i][1];
			d1[i]=a[i][1];
			cz[i]=a[i][1]-a[i][2];
			if(a[i][3]==0) juq3++;
			if(a[i][2]==0) juq2++;
		}
		int juq=0;
	
		if(juq3==n&&juq2==n)
		{
			int juq=0;
			sort(d1+1,d1+1+n,cmp);
			for(int i=1;i<=n/2;i++) juq+=d1[i];
			cout<<juq<<endl;
		}
		if(juq3==n&&juq2!=n)
		{
			sort(cz+1,cz+1+n);
			for(int i=1;i<=n/2;i++) jsq-=cz[i];
			cout<<jsq<<endl;
		}
		else
		{
			for(int i=1;i<=3;i++)
			{
				for(int j=1;j<=3;j++)
				{
					if(j!=i)juq=max(juq,a[1][i]+a[2][j]);
				}
			}
			cout<<juq<<endl;
		}
	}
	return 0;
}
