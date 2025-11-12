#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, k;
	cin >> n >> k;
	bool flag1 = true, flag0 = true;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != 1) flag1 = false;
		if(a[i] != 1 && a[i] != 0) flag0 = false;
	} 
	if(n <= 2 && k == 0 && flag1 == true)
	{
		cout << 1;
		return 0;
	}
	if(flag1 == true && k == 0)
	{
		cout << n / 2;
		return 0;
	}
	if(flag1 == true && k == 1)
	{
		cout << n;
		return 0;
	}
	if(flag0 == true && k == 0) 
	{
		int ans0 = 0, ans1 = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i] == 1) ans1++;
			if(a[i] == 0) ans0++;
		}
		cout << ans0 + ans1 / 2;
		return 0;
	}
	if(flag0 == true && k == 1) 
	{ 
		int ans0 = 0, ans1 = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i] == 1) ans1++;
			if(a[i] == 0) ans0++;
		}
		cout << ans1;
		return 0;
	}
	return 0;
}
