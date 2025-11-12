#include<bits/stdc++.h>
using namespace std;

const int maxn = 5005;
int n,sum;
int num[maxn],ma[maxn],q[maxn];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> num[i];
		ma[i] = max(num[i],ma[i]);
		q[i] = q[i-1] + num[i];
	}
	if (q[2] > ma[2]*2) sum++;
	if (q[3]-q[1] > ma[3]*2) sum++;
	if (q[3] > ma[3]*2) sum++;
	if (num[3]+num[1] > max(num[1],num[3])*2) sum++;
	cout << sum % 998244353;
	return 0;
}
