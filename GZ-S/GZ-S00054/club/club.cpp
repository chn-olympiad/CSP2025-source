//GZ-S00054 刘宸浩 兴义市第八中学 
#include<bits/stdc++.h>
using namespace std;
int t,n;
const int N=1e5+5;
int a[N][3];
int b[3],c[3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t>>n;
	while(t--)
	{
		int ans=0;
	
		
		for(int i=1;i<=n;i++)
		{
			int maxn=-9999999,p=0;
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(c[j]==n/2) a[i][j]=-1;
				if(maxn<=a[i][j])
				{
					maxn=a[i][j];
					p=j;
				}
			} 
			b[p]+=maxn;
			c[p]++;
		}
		for(int i=1;i<=3;i++) ans+=b[i];
		cout<<ans<<"\n";
	}
	return 0;
} 
