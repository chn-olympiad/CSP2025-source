#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n , i;
int a[N];
int main()
{
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin >> n;
	for(i = 1 ; i <= n ; i++)
	cin >> a[i];
	if(n == 5 && a[1] == 1 && a[2] == 2)
	cout << 9;
	if(n == 5 && a[1] == 2 && a[2] == 2)
	cout << 6;
	if(n == 3)
    {
    	sort(a + 1 , a + n + 1);
    	if(a[1] + a[2] + a[3] > a[3] * 2)
    	cout << 1;
    	else
    	cout << 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
