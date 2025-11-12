#include<bits/stdc++.h> 
using namespace std;
struct node{
	long long ma,mid,mi,k,jb;
};
node b[100005];
long long n,a[100005][4],k1,k2,jb1,jb2,t,c[4],num;
bool cmp(node x,node y)
{
	return x.k>y.k;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t>0)
	{
		t--;
		cin>>n;
		c[1]=0;
		c[2]=0;
		c[3]=0;
		num=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			k1=0;
			k2=100000;
			for(int j=1;j<=3;j++)
			{
				if(a[i][j]>k1)
				{
					k1=a[i][j];
					jb1=j;
				}
				if(a[i][j]<k2)
				{
					k2=a[i][j];
					jb2=j;
				}
			}
			b[i].ma=jb1;
			b[i].mi=jb2;
			b[i].mid=6-jb1-jb2;
			b[i].k=a[i][b[i].ma]-a[i][b[i].mid];
			b[i].jb=i;
		}
		sort(b+1,b+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			if(c[b[i].ma]==n/2)
			{
				c[b[i].mid]++;
				num+=a[b[i].jb][b[i].mid];
			}
			else
			{
				c[b[i].ma]++;
				num+=a[b[i].jb][b[i].ma];
			}
		}
		cout<<num<<endl;
	}
	return 0;
}
