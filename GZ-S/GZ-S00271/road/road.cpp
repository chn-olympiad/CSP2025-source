//GZ-S00271 贵阳市第三中学 杨鑫豪 
#include<bits/stdc++.h>
using namespace std;
int n,m,k,b[15][1000005],o,ma=INT_MAX;
struct s
{
	int l,r,o;
};
s a[1000005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].l>>a[i].r>>a[i].o;
	}
	for(int i=1;i<=k;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=n;j++)
		{
			
			cin>>b[i][j];
			b[i][j]+=x;
			o+=b[i][j];
		}
		ma=min(ma,o);
	}
	cout<<ma;
	return 0;
}
