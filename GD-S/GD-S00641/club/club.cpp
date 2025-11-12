#include <bits/stdc++.h>
const int maxn = 1e5+10;
using namespace std;
int men[4][maxn];
int p[maxn][4];// 第i个人第j大的选项 
int csize[4];
struct point
{
	int ws, wt, oi;
};
bool cmp(point a, point b)
{
	if(a.ws!=b.ws) return a.ws<b.ws;
	else if(a.wt != b.wt) return a.wt<b.wt;
	else return true;
}
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>men[1][i]>>men[2][i]>>men[3][i];
	int con = 0;
	vector<point> vee;
	csize[1] = csize[2] = csize[3] = 0;
	for(int i=1;i<=n;i++)
	{
		vector<int> v = {1,2,3};
		if(men[v[0]][i] < men[v[1]][i]) swap(v[0], v[1]);
		if(men[v[1]][i] < men[v[2]][i]) swap(v[1], v[2]);
		if(men[v[0]][i] < men[v[1]][i]) swap(v[0], v[1]);
		for(int j=1;j<=3;j++) p[i][j] = v[j-1];
		con+=men[v[0]][i];
		csize[v[0]]++;
		vee.push_back({men[p[i][1]][i]-men[p[i][2]][i], men[p[i][1]][i]-men[p[i][3]][i], i});
	}
//	for(auto pds:vee)
//	{
//		cout<<pds.ws<<' '<<pds.wt<<' '<<pds.oi<<'\n';
//	}
	vector<int> v = {1,2,3};
	if(csize[v[0]] < csize[v[1]]) swap(v[0], v[1]);
	if(csize[v[1]] < csize[v[2]]) swap(v[1], v[2]);
	if(csize[v[0]] < csize[v[1]]) swap(v[0], v[1]);
	if(csize[v[0]]>n/2)
	{
		//cout<<v[0]<<' ';
		int er = csize[v[0]];
		sort(vee.begin(), vee.end(), cmp);
		int cnt = 0;
		for(int i=0;cnt<er-n/2 && i<n;i++)
		{
			int cws = vee[i].ws, cwt = vee[i].wt, ci = vee[i].oi;
			//cout<<ci<<":"<<p[ci][1]<<' '<<p[ci][2]<<' '<<p[ci][3]<<'\n';
			if(p[ci][1]!=v[0]) 
			{
				continue;
			}
			if(csize[p[ci][2]]+1 <= n/2)
			{
				con-=cws;
				csize[p[ci][2]]++;
			}
			else
			{
				con-=cwt;
				csize[p[ci][3]]++;
			}
			cnt++;
		}
		cout<<con<<'\n';
	}
	else cout<<con<<'\n';
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin>>t;
	while(t--) solve();
	fclose(stdin);
	fclose(stdout);
}
