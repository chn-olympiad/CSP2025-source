#include<bits/stdc++.h>
using namespace std;
long long t,n,sum,b[5],e[100005][5],c[5][100005],m;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int l=1;l<=t;l++)
	{
		cin>>n;
		sum=0;
		b[1]=0;
		b[2]=0;
		b[3]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>e[i][1]>>e[i][2]>>e[i][3];
			m=max(e[i][1],max(e[i][2],e[i][3]));
			sum+=m;
			if(e[i][1]==m)
			{
				b[1]++;
				c[1][b[1]]=m-max(e[i][2],e[i][3]);
				continue;
			}
			if(e[i][2]==m)
			{
				b[2]++;
				c[2][b[2]]=m-max(e[i][1],e[i][3]);
				continue;
			}
			if(e[i][3]==m)
			{
				b[3]++;
				c[3][b[3]]=m-max(e[i][1],e[i][2]);
				continue;
			}
		}
		if(b[1]>n/2)
		{
			sort(c[1]+1,c[1]+b[1]+1);
			for(int i=1;i<=b[1]-n/2;i++)
			{
				sum-=c[1][i];
			}
		}
		if(b[2]>n/2)
		{
			sort(c[2]+1,c[2]+b[2]+1);
			for(int i=1;i<=b[2]-n/2;i++)
			{
				sum-=c[2][i];
			}
		}
		if(b[3]>n/2)
		{
			sort(c[3]+1,c[3]+b[3]+1);
			for(int i=1;i<=b[3]-n/2;i++)
			{
				sum-=c[3][i];
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
