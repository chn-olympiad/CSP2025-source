#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

struct Node
{
	long long cha,fz,from,id,hh;
	const operator <(const Node& a) const
	{
		return cha > a.cha;
	}
};

long long T,n,ans[4],lyy;
bool vis[N];
priority_queue <Node> q;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(long long i = 1;i <= n;i++)
		{
			long long A,B,C;
			cin >> A >> B >> C;
			if(A >= B && A >= C)
			{
				ans[1]++,lyy += A;
				q.push((Node){A - B,2,1,i,A - C});
				q.push((Node){A - C,3,1,i,A - B});
			}
			else if(B >= A && B >= C)
			{
				ans[2]++,lyy += B;
				q.push((Node){B - A,1,2,i,B - C});
				q.push((Node){B - C,3,2,i,B - A});
			}
			else if(C >= A && C >= B)
			{
				ans[3]++,lyy += C;
				q.push((Node){C - A,1,3,i,C - B});
				q.push((Node){C - B,2,3,i,C - A});
			}
		}
		while((ans[1] * 2 > n || ans[2] * 2 > n || ans[3] * 2 > n) && !q.empty())
		{
			Node now = q.top();
			q.pop();
			ans[now.fz]++,ans[now.from]--;
			if(!vis[now.id]) lyy -= now.cha,vis[now.id] = 1;
			else lyy = lyy - now.cha + now.hh;
		}
		cout << lyy << "\n";
		lyy = 0;
		ans[1] = ans[2] = ans[3] = 0;
		while(!q.empty()) q.pop();
		memset(vis,0,sizeof(vis));
	}
	return 0;
}
