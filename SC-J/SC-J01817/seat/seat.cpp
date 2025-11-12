#include <bits/stdc++.h>
using namespace std;

const int N=1e2+5;
int n, m, arr[N];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i=1;i<=n*m;i++) cin >> arr[i];
	int r=arr[1];
	sort(arr+1, arr+n*m+1, cmp);
	int i=1, j=1, a=1;
	bool f=0;
	while (j<=m){
		//cout << a <<" "<<i<<" "<<j<< endl;
		if (arr[a] == r) {
			cout << j << " " << i;
			break;
		}
		if (i == n && !f) {
			f = 1;
			j++;
		} 
		else if (i == 1 && f) {
			f = 0;
			j++;
		}
		else if (!f)i++;
		else i--;
		a++;
	}
	return 0;
}