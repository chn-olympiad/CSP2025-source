#include <bits/stdc++.h>
using namespace std;
string n;
int a, A[1000100], g = 1;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> n;
	a = n.length();
	for(int i(0); i < a; ++i)	
	{
		if(n[i] >= '0' && n[i] <= '9')
		{
			A[g] = n[i]-48;
			++g; 
		}
	}
	sort(A, A+g);
	for(int i(g-1); i >= 1; --i)
		cout << A[i];
	return 0;
} 	
