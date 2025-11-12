#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, s1 = 0, s0 = 0;
	cin >> n >> k;
	if(n == 1)
    {
        int x;
        cin >> x;
        if(x == k) cout << 1;
        else cout << 0;
        return 0;
    }
	for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i] == 1) s1++;
        if(a[i] == 0) s0++;
    }
    if(s1 == n)
    {
        cout << n / 2;
        return 0;
    }
    if(s0 == n)
    {
        if(k == 1) cout << 0;
        if(k == 0) cout << n;
        return 0;
    }
    if(s1 + s0 == n)
    {
        if(k == 1) cout << s1;
        return 0;
    }
	return 0;
}
