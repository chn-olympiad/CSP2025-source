#include <bits/stdc++.h>
using namespace std;

int n,k,cnt,num,sum;
int a[500005];
bool f = true,b[500005];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>> n >> k;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++)
	{
		if(a[i] != 1) f = false;
		if(a[i] == 1) cnt++;
		if(a[i] == 0) num++;
	}
	for(int i = 1;i <= n;i++)
	{
		if(b[i] == false && a[i] == 1 && a[i+1] == 1)
		{
			sum++;
			b[i+1] = true;
		}
	}
	if(f) cout << n/2;
	else if(k == 1) cout << cnt;
	else if(k == 0) cout << num+sum;
	else cout << max(num,max(cnt,sum));
	return 0;
}