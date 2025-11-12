#include<bits/stdc++.h>
using namespace std;
long long n,a[100001][4];
bool cmp (long long x,long long y)
{
	return a[x][3]<a[y][3];
}
void zxy ()
{
	long long b[3][100001],ans=0;
	b[0][0]=b[1][0]=b[2][0]=0;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
	for (int i=1;i<=n;i++)
	{
		long long maxx=max(a[i][0],max(a[i][1],a[i][2]));
		if (maxx==a[i][0]) 
		{
			long long manx=max(a[i][1],a[i][2]);
			b[0][0]++;
			b[0][b[0][0]]=i;
			a[i][3]=maxx-manx;
		}
		else if (maxx==a[i][1]) 
		{
			long long manx=max(a[i][0],a[i][2]);
			b[1][0]++;
			b[1][b[1][0]]=i;
			a[i][3]=maxx-manx;
		}
		else
		{
			long long manx=max(a[i][1],a[i][0]);
			b[2][0]++;
			b[2][b[2][0]]=i;
			a[i][3]=maxx-manx;
		}
	}
	for (int i=0;i<=2;i++)
	{
		if (b[i][0]>n/2)
		{
			sort(b[i]+1,b[i]+b[i][0]+1,cmp);
			for (int j=1;j<=b[i][0]-n/2;j++) ans-=a[b[i][j]][3];
		}
		for (int j=1;j<=b[i][0];j++) ans+=a[b[i][j]][i];
	}
	cout<<ans<<endl; 
}
int main ()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while (t--) zxy();
	return 0;
}
