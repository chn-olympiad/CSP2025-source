#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
using ll = long long;

int n;
ll k, ans = 0, arr[N];
bool used[N];

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 1; j + i <= n; j++)
		{
			if(used[j] == 1) continue;
			ll num = 0;
			bool flag = true;
			for(int l = j; l <= j+i; l++)
			{
				if(used[l] == 1)
				{
					j = l;
					flag = false;
					break;
				}
				
				if(i == 0 && arr[l] == k)
				{
					ans++;
					flag = false;
//					cout << i << " "<< j << endl;//~!!
					used[l] = 1;
				}
				else 
				{
					num = num ^ arr[l];
				}
			}
			
			if(flag && num == k)
			{
				ans++;
//				cout << i  << " "<< j << endl;//1£¡1 
				for(int l = j; l <= j+i; l++)
				{
					used[l] = 1;
				}
			}
		}
	}
	
	cout << ans;
	return 0;
}
