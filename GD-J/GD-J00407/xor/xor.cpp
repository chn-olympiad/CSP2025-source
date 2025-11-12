#include<iostream>
using namespace std;
const int N = 5e5 + 10;
int a[N],x[N],cnt,len;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	x[0] = 0;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	for(int i = 1;i <= n;i++)
	{
		len++;
		x[len] = (x[len - 1] ^ a[i]);
//		cout << len << ' ' << x[len - 1] << ' ' << a[i] << ' '<< x[len] << '\n';
		if(a[i] == k || x[len] == k)
			cnt++,len = 0;
	}
	if(x[len] == k)
		cnt++;
	cout << cnt;
	return 0;
}
