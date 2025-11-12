#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n,k;
int a[N],b[N];
int sum = 0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a + 1,a + n + 1);
	if((n <= 2 || n <= 100) && k == 0 && a[1] == 1 && a[n] == 1){
		cout << n << '\n';
		return 0;
	}
	return 0;
}
