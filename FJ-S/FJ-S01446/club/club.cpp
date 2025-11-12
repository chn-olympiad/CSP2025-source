#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N][3],ans,id[N];
int mx(int x,int y,int z)
{
	if (x>=y&&x>=z) return 0;
	if (y>=x&&y>=z) return 1;
	return 2;
}
void solve()
{
	ans=0;
	scanf("%d",&n);
	int c[3]={0};
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		int o=mx(a[i][0],a[i][1],a[i][2]);
		id[i]=o;
		ans+=a[i][o],c[o]++;
	}
	int al=mx(c[0],c[1],c[2]);
	if (c[al]<=n/2) return printf("%d\n",ans),void();
	vector<int> b;
	for (int i=1;i<=n;i++)
		if (id[i]==al)
		{
			if (al==0) b.push_back(-a[i][0]+max(a[i][1],a[i][2]));
			else if (al==1) b.push_back(-a[i][1]+max(a[i][0],a[i][2]));
			else b.push_back(-a[i][2]+max(a[i][0],a[i][1]));
		}
	sort(b.begin(),b.end(),greater<int>());
	for (int i=0;i<c[al]-n/2;i++) ans+=b[i];
	printf("%d\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int TT;
	cin>>TT;
	while (TT--) solve();
	return 0;
}
