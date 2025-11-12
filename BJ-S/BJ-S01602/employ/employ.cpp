#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n,m,ans;
string s;
int ling,yi;
int c[N];
int box[N];
void dfs(int cur,int lingnum,int yinum,int ren,int fai)
{
	if (cur > n)
	{
		for (int i = 1;i <= n;i++)
		{
			//cout<<box[i];
		}
		//cout<<" "<<ren<<" "<<fai<<'\n';
		if (ren >= m) ans++;
		return ;
	}
	if (n-cur+1 + ren < m) return ;
	//cout<<cur<<" "<<ren<<" "<<fai<<'\n';
	if (yinum < yi)
	{
		box[cur] = 1;
		//cout<<"ren="<<ren<<",fai="<<fai<<'\n';
		if (fai < c[cur]) dfs(cur+1,lingnum,yinum+1,ren+1,fai);
		else dfs(cur+1,lingnum,yinum+1,ren,fai+1);
	}
	if (lingnum < ling)
	{
		box[cur] = 0;
		dfs(cur+1,lingnum+1,yinum,ren,fai+1);
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	//zhushi jide shan
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for (int i = 1;i <= n;i++)
	{
		if (s[i-1] == '0') ling++;
		else yi++;
	}
	dfs(1,0,0,0,0);
	cout<<ans;
	return 0;
}
