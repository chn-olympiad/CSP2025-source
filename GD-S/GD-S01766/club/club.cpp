#include<bits/stdc++.h> 
using namespace std;
const int N = 1e5 + 10;
int t, n, a[N][5], cnt1, cnt2, cnt3, b[N][3];
int id[N];
bool v[N][3];
priority_queue<pair<int, int>> q1, q2, q3;
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while(t--)
	{
		cnt1 = cnt2 = cnt3 = 0;
		memset(b, 0, sizeof(b));
		memset(id, 0, sizeof(id));
		memset(v, 0, sizeof(v));
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		while(!q3.empty()) q3.pop();
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
		for(int i = 1; i <= n; i++)
		{
			if(a[i][1] > a[i][2] && a[i][1] > a[i][3]) {
				cnt1++, id[i] = 1;
				b[i][2] = a[i][1] - a[i][2], b[i][3] = a[i][1] - a[i][3];
				v[i][1] = true;
				q1.push({-b[i][2], i}), q1.push({-b[i][3], i});
			}
			else if(a[i][2] > a[i][1] && a[i][2] > a[i][3])	{
				cnt2++, id[i] = 2, v[i][2] = true;
				b[i][1] = a[i][2] - a[i][1], b[i][3] = a[i][2] - a[i][3];
				q2.push({-b[i][1], i}), q2.push({-b[i][3], i});
			}
			else {
				cnt3++, id[i] = 3, v[i][3] = true;
				b[i][1] = a[i][3] - a[i][1], b[i][2] = a[i][3] - a[i][2];
				q3.push({-b[i][1], i}), q3.push({-b[i][2], i});
			}
		}
		while(cnt1 > n / 2 || cnt2 > n / 2 || cnt3 > n / 2)
		{
			int v1 = 0;
			while(!q1.empty())
			{
				if(cnt1 <= n / 2 && v1 == 0) break;
				int val = -q1.top().first, i = q1.top().second;
				q1.pop();
				if(id[i] != 1) continue;
				if(b[i][2] == val && v[i][2] == false) {
					if(cnt1 <= n / 2 && -b[i][3] != v1) break;
					v1 = -b[i][3];
					id[i] = 2, cnt1--;
					v[i][2] = true;
					cnt2++; q2.push({-b[i][3], i});
							
				}
				else if(v[i][3] == false){
					if(cnt1 <= n / 2 && -b[i][2] != v1) break;
					v1 = -b[i][2];
					id[i] = 3, cnt1--;
					v[i][3] = true;
					cnt3++;
					q3.push({-b[i][2], i});
				}
			}
			v1 = 0;
			while(!q2.empty())
			{
				if(cnt2 <= n / 2 && v1 == 0) break;
				int val = -q2.top().first, i = q2.top().second;
				q2.pop();
				if(id[i] != 2) continue;
				if(b[i][1] == val && v[i][1] == false) {
					if(cnt2 <= n / 2 && -b[i][3] != v1) break;
					v1 = -b[i][3];
					id[i] = 1;	
					v[i][1] = true;
					cnt1++, cnt2--;
					q1.push({-b[i][3], i});
					
				}
				else if(v[i][3] == false){
					if(cnt2 <= n / 2 && -b[i][1] != v1) break;
					v1 = -b[i][1];
					id[i] = 3;
					v[i][3] = true;
					cnt3++,	cnt2--;
					q3.push({-b[i][1], i});
				}
			}
			v1 = 0;
			while(!q3.empty())
			{
				if(cnt3 <= n / 2 && v1 == 0) break;
				int val = -q3.top().first, i = q3.top().second;
				q3.pop();
				if(id[i] != 3) continue;
				if(b[i][1] == val && v[i][1] == false) {
					if(cnt3 <= n / 2 && -b[i][2] != v1) break;
					v1 = -b[i][2];
					id[i] = 1;
					v[i][1] = true;	
					cnt1++, cnt3--;
					q1.push({-b[i][2], i});
					
				}
				else if(v[i][2] == false){
					if(cnt3 <= n / 2 && -b[i][1] != v1) break;
					v1 = -b[i][1];
					id[i] = 2;
					v[i][2] = true;
					cnt2++, cnt3--;
					q2.push({-b[i][1], i});
				}
			}
		}
		long long ans = 0;
		for(int i = 1; i <= n; i++)
			ans += a[i][id[i]];
		printf("%lld\n", ans);
	}
	return 0;
}
