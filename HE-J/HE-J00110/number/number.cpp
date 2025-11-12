#include <bits/stdc++.h>
using namespace std;
string n;
int a[1000005];
bool cmp(int x , int y){
	return x > y;
}
int main()
{
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	cin >> n;
	int x = 0;
	for (int i = 0 ; i < n.length() ; i++)
		if ((int)n[i] >= 48 && (int)n[i] <= 57)
			a[++x] = (int)n[i] - 48;
	sort(a + 1 , a + x + 1 , cmp);
	for (int i = 1 ; i <= x ; i++){
		if (a[1] == 0){
			cout << 0;
			return 0;
		}
		else cout << a[i];
	}
	return 0;
}
