#include<bits/stdc++.h>
using namespace std;
const int MAX=5000;
int a[MAX][4],b[10000],c[MAX];
int maxx[MAX];
int res,cnt;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,m=1;
	cin>>n;
	for(int k=1;k<t;k++)
	{
		m=1;cnt=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				b[m]=a[i][j];
				m++;
			}
		}
		sort(b+1,b+m+1);
		for(int i=m;i>=1;i--)	
		{
			cnt++;
			if(b[i] && cnt<=n/2)	
			{
				res+=b[i];
			}
			
		}
			cout<<res;
			res=0;
		for(int i=1;i<=m;i++)	b[i]=0;
	}
	return 0;
}
