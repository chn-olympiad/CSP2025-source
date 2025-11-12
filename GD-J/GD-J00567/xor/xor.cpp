#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
struct node{int l,r;};
int a,s[500005],n,cnt,now,k;
bool operator <(node a,node b)
{
	return a.r<b.r;
} 
vector<node>ans;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin >> n >> k;
	for(int i = 1;i<=n;i++)
	{
		cin >> a;
		s[i]=s[i-1]^a;
	}
	for(int i = 1;i<=n;i++)
		for(int j = i;j<=n;j++)
			if((s[j]^s[i-1])==k)
				ans.push_back({i,j});
	sort(ans.begin(),ans.end());
	for(node i:ans)
	{
		if(i.l>now)
		{
			cnt++;
			now=i.r;
		}
	}
	cout << cnt;
	return 0;
}
