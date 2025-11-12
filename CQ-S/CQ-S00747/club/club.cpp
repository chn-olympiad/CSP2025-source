//10min
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][3],T,n,cnt[3],mx[N];
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)for(int j=0;j<3;j++)scanf("%d",&a[i][j]);
	for(int i=0;i<3;i++)cnt[i]=0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int mxpos=0;
		for(int j=1;j<3;j++)if(a[i][j]>a[i][mxpos])mxpos=j;
		cnt[mxpos]++,ans+=a[i][mxpos];
		mx[i]=mxpos;
	}
	for(int i=0;i<3;i++)if(cnt[i]>n/2)
	{
		vector<int>temp;
		for(int j=1;j<=n;j++)if(mx[j]==i)temp.push_back({a[j][i]-max(a[j][(i+1)%3],a[j][(i+2)%3])});
		sort(temp.begin(),temp.end());
		for(int j=0;j<cnt[i]-n/2;j++)ans-=temp[j];
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}