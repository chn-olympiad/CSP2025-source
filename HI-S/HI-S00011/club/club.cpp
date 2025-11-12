#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int n;
int a[N][4],s[N];
int bl(int x,int a1,int a2,int a3)
{
	if(x>n)
		return 0;
	int ma=0;
	if(a1<n/2)
		ma=max(ma,bl(x+1,a1+1,a2,a3)+a[x][1]);
	if(a2<n/2)
		ma=max(ma,bl(x+1,a1,a2+1,a3)+a[x][2]);
	if(a3<n/2)
		ma=max(ma,bl(x+1,a1,a2,a3+1)+a[x][3]);
	return ma;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
				scanf("%d",&a[i][j]);
		}
		int ans=0;
		ans=bl(1,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
} 
