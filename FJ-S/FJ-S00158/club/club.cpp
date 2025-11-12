#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005][3],t[3],ans,id;
priority_queue<int> q;
pair<int,int> Max(int x,int y,int z)
{
	if(x >= y && x >= z) return {x,0};
	else if(y >= x && y >= z) return {y,1};
	else return {z,2};
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		ans = 0;
		t[0] = t[1] = t[2] = 0;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			ans += Max(a[i][0],a[i][1],a[i][2]).first;
			t[Max(a[i][0],a[i][1],a[i][2]).second]++;
		}
		int num = Max(t[0],t[1],t[2]).first;
		if(num > n/2)
		{
			id = Max(t[0],t[1],t[2]).second;
			while(!q.empty()) q.pop();
			for(int i = 1;i <= n;i++)
			{
				if(Max(a[i][0],a[i][1],a[i][2]).second == id)
				{
					if(id == 0) q.push(-abs(a[i][0]-max(a[i][1],a[i][2])));
					if(id == 1) q.push(-abs(a[i][1]-max(a[i][0],a[i][2])));
					if(id == 2) q.push(-abs(a[i][2]-max(a[i][0],a[i][1])));
				}
			}
			while(num > n/2)
			{
				ans += q.top();
				q.pop();
				num--;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

