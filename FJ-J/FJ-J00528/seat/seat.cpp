#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)
		cin >> a[i];
	int num = a[1];
	sort(a + 1,a + n * m + 1,greater<int>());
	int x = lower_bound(a + 1,a + n * m + 1,num,greater<int>()) - a;
	cout << (x - 1) / n + 1 << " ";
	if(((x - 1) / n + 1) & 1)
		cout << (x - 1) % n + 1 << "\n";
	else cout << n - (x - 1) % n << "\n";
	return 0;
}

