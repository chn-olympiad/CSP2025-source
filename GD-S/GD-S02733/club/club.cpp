#include <bits/stdc++.h>
using namespace std;

struct node
{
	int id,sc;
	bool operator <(const node &o) const
	{
		return sc > o.sc;
	}
};
int cntm[4],a[100005][4],c[4],maxi,maxj,maxk;
bool m[4];
priority_queue <node> q[4];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while (t--)
	{
		memset(a,0,sizeof(a)),memset(cntm,0,sizeof(cntm)),memset(m,0,sizeof(m));
		int n;
		long long ans = 0;
		cin >> n;
		for (int i = 1;i <= n;i++) 
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			memset(c,0,sizeof(c));
			if (a[i][1] > a[i][2] && a[i][1] > a[i][3]) maxi = 1;
			else if (a[i][2] > a[i][1] && a[i][2] > a[i][3]) maxi = 2;
			else maxi = 3;
			//cout << "/maxi " << maxi << " " << i << endl;
			if (m[maxi]) 
			{
				node x = q[maxi].top();
				for (int j = 1;j <= 3;j++) 
				{
					if (j == maxi) continue;
					if (!c[0]) c[0] = x.sc + a[i][j],c[2] = a[x.id][j] + a[i][maxi],maxj = j;
					else c[1] = x.sc + a[i][j],c[3] = a[x.id][j] + a[i][maxi],maxk = j;
				}
				//cout << "/max " << maxi << " " << maxj << " " << maxk << endl;
				if (c[0] >= c[1] && c[0] >= c[2] && c[0] >= c[3])
				{
					if (m[maxj]) 
					{
						node y = q[maxj].top();
						if (y.sc + a[i][maxk] > a[y.id][maxk] + a[i][maxj]) q[maxk].push({i,a[i][maxk]});
						else q[maxj].pop(),q[maxj].push({i,a[i][maxj]}),q[maxk].push({y.id,a[y.id][maxk]});
						cntm[maxk]++;
						if (cntm[maxk] == n / 2) m[maxk] = true;
					}
					else q[maxj].push({i,a[i][maxj]}),cntm[maxj]++,m[maxj] = (cntm[maxj] == n / 2 ? true : false);
				}
				else if (c[1] >= c[0] && c[1] >= c[2] && c[1] >= c[3])
				{
					if (m[maxk]) 
					{
						node y = q[maxk].top();
						if (y.sc + a[i][maxj] > a[y.id][maxj] + a[i][maxk]) q[maxj].push({i,a[i][maxj]});
						else q[maxk].pop(),q[maxk].push({i,a[i][maxk]}),q[maxj].push({y.id,a[y.id][maxj]});
						cntm[maxj]++;
						if (cntm[maxj] == n / 2) m[maxj] = true;
					}
					else q[maxk].push({i,a[i][maxk]}),cntm[maxk]++,m[maxk] = (cntm[maxk] == n / 2 ? true : false);
				}
				else if (c[2] >= c[1] && c[2] >= c[0] && c[2] >= c[3])
				{
					if (m[maxj]) 
					{
						node y = q[maxj].top();
						if (y.sc + a[x.id][maxk] > a[y.id][maxk] + a[x.id][maxj]) q[maxk].push({x.id,a[x.id][maxk]});
						else q[maxj].pop(),q[maxj].push({x.id,a[x.id][maxj]}),q[maxk].push({y.id,a[y.id][maxk]});
						cntm[maxk]++;
						if (cntm[maxk] == n / 2) m[maxk] = true;
					}
					else q[maxi].pop(),q[maxi].push({i,a[i][maxi]}),q[maxj].push({x.id,a[x.id][maxj]}),cntm[maxj]++,m[maxj] = (cntm[maxj] == n / 2 ? true : false);
				}
				else
				{
					if (m[maxk]) 
					{
						node y = q[maxk].top();
						if (y.sc + a[x.id][maxj] > a[y.id][maxj] + a[x.id][maxk]) q[maxj].push({x.id,a[x.id][maxj]});
						else q[maxk].pop(),q[maxk].push({x.id,a[x.id][maxk]}),q[maxj].push({y.id,a[y.id][maxj]});
						cntm[maxj]++;
						if (cntm[maxj] == n / 2) m[maxj] = true;
					}
					else q[maxi].pop(),q[maxi].push({i,a[i][maxi]}),q[maxk].push({x.id,a[x.id][maxk]}),cntm[maxk]++,m[maxk] = (cntm[maxk] == n / 2 ? true : false);
				}
			}
			else
			{
				cntm[maxi]++;
				q[maxi].push({i,a[i][maxi]});
				if (cntm[maxi] == n / 2) m[maxi] = true;
			}
			//cout << "//qlen:" << q[1].size() << " " << q[2].size() << " " << q[3].size() << endl;
		}
		while (!q[1].empty()) /*printf("//ans:%d ",q[1].top().id),*/ans += q[1].top().sc,q[1].pop();
		while (!q[2].empty()) /*printf("//ans:%d ",q[2].top().id),*/ans += q[2].top().sc,q[2].pop();
		while (!q[3].empty()) /*printf("//ans:%d ",q[3].top().id),*/ans += q[3].top().sc,q[3].pop();
		cout << ans << endl;
	}
	return 0;
}
