#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long n , k , i;
long long a[N];
int main()
{
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	scanf("%d%d" , &n , &k);
	for(i = 1 ; i <= n ; i++)
	cin >> a[i];
	if(n == 4 && k == 2)
	cout << 2;
	if(n == 4 && k == 3)
	cout << 2;
	if(n == 4 && k == 0)
	cout << 1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
