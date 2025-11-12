#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e5+5;
int n,m,ans,b[5],c[5];
vector<int> vt[5];
void solve()
{
	ans=0;
	cin>>n;
	for(int i=1;i<=3;i++)
		vt[i].clear();
	for(int i=1,x;i<=n;i++)
	{
		cin>>b[1]>>b[2]>>b[3];
		c[1]=b[1],c[2]=b[2],c[3]=b[3];
		sort(b+1,b+4);
		if(c[1]==b[3])
			x=1;
		else if(c[2]==b[3])
			x=2;
		else
			x=3;
		vt[x].push_back(b[3]-b[2]);
		ans+=b[3];
	}
	for(int i=1;i<=3;i++)
	{
		if(vt[i].size()<=n/2)
			continue;
		sort(vt[i].begin(),vt[i].end());
		for(int j=0;vt[i].size()-j-1>=n/2;j++)
			ans-=vt[i][j];
	}
	cout<<ans<<'\n';
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	cin>>T;
	while(T--)
		solve();
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
Ren5Jie4Di4Ling5%
*/
