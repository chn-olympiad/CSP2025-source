#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=100010;
int b[N],a[N][3],f[N],maxid[N],sum[3],maxn=0;
int cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int T;
	cin>>T;	
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) 
		{
			f[i]=0;
			b[i]=-100000000;
		}
		maxn=0;
		sum[0]=sum[1]=sum[2]=0;
		for(int i=1;i<=n;i++) 
		{
			int tmp=-1;
			for(int j=0;j<=2;j++) 
			{
				cin>>a[i][j];
				if(f[i]<a[i][j])
				{
					tmp=j;
					f[i]=a[i][j];
				}
			}
			maxid[i]=tmp;
			sum[tmp]++;
			maxn+=f[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=2;j++)
			{
				a[i][j]-=f[i];
			}
		}
		if(sum[0]<=(n/2)&&sum[1]<=(n/2)&&sum[2]<=(n/2)) cout<<maxn<<endl;
		else
		{
			int id,m;
			if(sum[0]>(n/2)) id=0,m=sum[0];
			else if(sum[1]>(n/2)) id=1,m=sum[1];
			else id=2,m=sum[2];
			for(int i=1;i<=n;i++)
			{
				if(maxid[i]!=id) continue;
				for(int j=0;j<=2;j++)
				{
					if(j==id) continue;
					b[i]=max(b[i],a[i][j]);
				}
			}
			sort(b+1,b+n+1,cmp);
			for(int i=1;i<=m-(n/2);i++) maxn+=b[i];
			cout<<maxn<<endl;
		}
		
	}

}