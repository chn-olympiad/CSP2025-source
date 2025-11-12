#include<bits/stdc++.h>
using namespace std;

int a[500005],b[500005];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt = 0,now = 0;
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
		
	if(k == 0 || k == 1)
	{
		for(int i = 1;i <= n;i++)
			if(a[i] == k) cnt++;
		cout << cnt;
		return 0;
	}
	cout << cnt;
	return 0;
}
