#include<bits/stdc++.h>
using namespace std;
int t,n;
bool B = true;
bool max_cmp(int x, int y)
{
	return x > y;
}
long long run(const vector< vector<int> > &a, vector<int> &num, long long sum, int now)
{
	long long ans = sum;
	if(now != n - 1)
	{
		if(B && a[now][0] && a[now][1] && num[2] < n/2)
		{
			num[2]++;
			ans = max(ans, run(a, num, sum + a[now][2], now + 1));
			num[2]--;
			return ans;
		}
		if(num[0] < n/2)
		{
			num[0]++;
			ans = max(ans, run(a, num, sum + a[now][0], now + 1));
			num[0]--;
		}
		if(num[1] < n/2)
		{
			num[1]++;
			ans = max(ans, run(a, num, sum + a[now][1], now + 1));
			num[1]--;
		}
		if(!B && num[2] < n/2)
		{
			num[2]++;
			ans = max(ans, run(a, num, sum + a[now][2], now + 1));
			num[2]--;
		}
	}
	else
	{
		if(num[0] < n/2)
		{
			num[0]++;
			ans = max(ans, sum + a[now][0]);
			num[0]--;
		}
		if(num[1] < n/2)
		{
			num[1]++;
			ans = max(ans, sum + a[now][1]);
			num[1]--;
		}
		if(num[2] < n/2)
		{
			num[2]++;
			ans = max(ans, sum + a[now][2]);
			num[2]--;
		}
	}
	return ans;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	while(t--)
	{
		cin >> n;
		vector< vector<int> > a(n , vector<int>(3 , 0));
		bool A = true;
		B = true;
		long long max_ans = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			if(a[i][1] != 0)
				A = false;
			if(a[i][2] != 0)
			{
				A = false;
				B = false;
			}
			max_ans += max(a[i][0], max(a[i][1], a[i][2]));
		}
		if(A)
		{
			int b[100009];
			for(int i = 0; i < n; i++)
				b[i] = a[i][0];
			sort(b, b + n, max_cmp);
			long long ans = 0;
			for(int i = 0; i < n/2; i++)
				ans += b[i];
			cout << ans << endl;
			continue;
		}
		
		if(B)
		{
			vector<int> choose(n , 0);
			long long ans = 0, temp = 0;
			for(int i = n / 2 - 1;i < n; i++)
				choose[i] = 1;
			for(int i = 0; i < n; i++)
				temp += a[i][choose[i]];
			if(temp > ans)
				ans = temp;
			if(ans < max_ans)
			{
			
			}
			cout << ans << endl;
		}
		
		vector<int> num(3 , 0);
		cout << run(a, num, 0, 0) << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
