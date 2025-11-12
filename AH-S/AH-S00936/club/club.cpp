#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
int a[N][3]; // 共3个部门， a[N][1]表示1部门, a[N][2]表示2部门, a[N][0]表示3部门
long long ans;
int ren[3];
int t;
int pl;
priority_queue<int> s;

void myd(int n)
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
		for(int i = 1; i <= 3*n; i++)
		{
			scanf("%d",&pl);
			a[pl][i%3]++;
			s.push(pl);
		}
	
		int lim = n / 2;
	
		while(n--)
		{
			int d = s.top();
		
		if(a[d][1] > 0 && ren[1] < lim)
		{
			ans += d;
			a[d][1]--;
			ren[1]++;
			s.pop();
		}	
		
		else if(a[d][2] > 0 && ren[2] < lim)
		{
			ans += d;
			a[d][2]--;
			ren[2]++;
			s.pop();
		}
		
		else if(a[d][0] > 0 && ren[0] < lim)
		{
			ans += d;
			a[d][0]--;
			ren[0]++;
			s.pop();
		}
		
	}
		cout << ans << endl;
}

int main()
{
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		memset(a, 0, sizeof a);
		memset(ren, 0, sizeof ren);
		ans = 0;
		pl = 0;
		while(s.size() != 0) s.pop();
		myd(n);
	}
	return 0;	
}
