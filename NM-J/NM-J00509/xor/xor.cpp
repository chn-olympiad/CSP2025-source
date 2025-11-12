#include <bits/stdc++.h>

using namespace std;
const int N = 5e5 + 10;

int n, k;
int a[N]; 

int s[N];

bool check (int x)
{
	int cnt = 0;
	
	s[0] = 0;
	int len = 0;
	int sum = 0;
	
	for (int i = 1; i <= n && cnt < x; i++)
	{
		 sum ^= a[i];
		 
		 s[++len] = s[len - 1] ^ a[i];
		 
		 for (int j = 0; j < len; j++)
		 {
		 	if ((sum ^ s[j]) == k)
		 	{
		 		cnt++;
		 		sum = 0;
		 		len = 0;
		 		s[0] = 0;
		 		break;
			}
		}
		
		if (cnt >= x)
			break;
	}
	
	if (cnt >= x)
		return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
		
	int L = 0, R = n + 1;
	while (L + 1 < R)
	{
		int M = (L + R) / 2;
		
		if (check(M))
			L = M;
		else
			R = M;
	}
	
	cout << L << endl;
	
	return 0;
}
