#include<iostream>
#include<map>
using namespace std;
int n,q;
int ans;
map <string,string> sounds;
map <string,bool> vis;
string x,y;
void dfs(string now,string bec,int l,int r)
{
	if(vis[now]) return;
	if(sounds[now] == bec) ans++;
	vis[now] = 1;
	if(l) dfs(x[l - 1] + now,y[l - 1] + bec,l - 1,r);
	if(r + 1 < x.size()) dfs(now + x[r + 1],bec + y[r + 1],l,r + 1);
	return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
		string a,b;
		cin >> a >> b;
		sounds[a] = b;
	}
	while(q--)
	{
		vis.clear();
		ans = 0;
		cin >> x >> y;
		if(x.size() != y.size())
		{
			cout << 0 << '\n';
			continue;
		}
		int start_dif = -1,end_dif = -1;
		string diff = "",sentto = "";
		for(int i = 0;i < x.size();i++)
		{
			if(x[i] != y[i])
			{
				if(start_dif == -1) start_dif = i;
				end_dif = i;
			}
		}
		for(int i = start_dif;i <= end_dif;i++) diff += x[i],sentto += y[i];
		dfs(diff,sentto,start_dif,end_dif);
		cout << ans << '\n';
	}
}
