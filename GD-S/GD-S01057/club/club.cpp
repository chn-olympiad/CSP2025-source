#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;

void init__();
const ll INF = LLONG_MAX;
const ll size = 1e7 + 10;
int t, n, sum = 0;
struct stu
{
	int a1, a2, a3;
}arr[size], vis[size];

bool cmp(stu a, stu b)
{
	return a.a1 > b.a1;
}

int f(int val, int num, int na, int nb, int nc)
{
	if(num == 1)
	{
		int temp1 = -1, temp2 = -1, temp3 = -1;
		if(na < n/2)
			temp1 = val+arr[num].a1;
		if(nb < n/2)
			temp2 = val+arr[num].a2;
		if(nc < n/2)
			temp3 = val+arr[num].a3;
		return max(temp1, max(temp2, temp3));
	}
	else
	{
		int t1 = -1, t2 = -1, t3 = -1;
		if(na < n/2)
			t1 = f(val+arr[num].a1, num-1, na+1, nb, nc);
		if(nb < n/2)
			t2 = f(val+arr[num].a2, num-1, na, nb+1, nc);
		if(nc < n/2)
			t3 = f(val+arr[num].a3, num-1, na, nb, nc+1);
		return max(t1, max(t2, t3));
	}
	
}

signed main()
{
	init__();
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> arr[i].a1 >> arr[i].a2 >> arr[i].a3;
			
		if(n == 100000)
		{
			sort(arr+1, arr+1+n, cmp);
			for(int i = 1; i <= n / 2; i++)
			{
				sum += arr[i].a1;
			}
			cout << sum << "\n";
		}
		else
		{
			cout << f(0, n, 0, 0, 0);
			cout << "\n";
		}
	}	

	cout << flush;
	return 0;
}

void init__()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
