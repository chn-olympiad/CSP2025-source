#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
long long a[maxn][3];
long long c[305][155][155];
struct ss
{
	int A,B,C;
}aa[maxn];
bool cmp(ss A,ss B)
{
	return A.A-A.B>B.A-B.B;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		if(n>300)
		{
			for(int i=1;i<=n;i++)cin>>aa[i].A>>aa[i].B>>aa[i].C;
			sort(aa+1,aa+1+n,cmp);
			int m=n/2;
			long long s=0;
			for(int i=1;i<=m;i++)s+=aa[i].A+aa[i+m].B;
			cout<<s<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
		for(int i=0;i<305;i++)for(int j=0;j<155;j++)for(int l=0;l<155;l++)c[i][j][l]=-1e15; 
		int m=n/2;
		c[0][0][0]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=i;j++)
			{
				if(j>m)break;
				for(int l=0;l<=i;l++)
				{
					if(l>m)break;
					if(j+l>i)break;
					int A=j,B=l,C=i-j-l;
					if(A!=0)c[i][j][l]=max(c[i][j][l],c[i-1][j-1][l]+a[i][0]);
					if(B!=0)c[i][j][l]=max(c[i][j][l],c[i-1][j][l-1]+a[i][1]);
					if(C!=0)c[i][j][l]=max(c[i][j][l],c[i-1][j][l]+a[i][2]);
				} 
			}
		}
		long long z=0;
		for(int i=0;i<=m;i++)
		{
			for(int j=0;j<=m;j++)
			{
				int C=n-i-j;
				if(C>m)continue;
				z=max(z,c[n][i][j]);
			}
		}
		cout<<z<<'\n';
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
