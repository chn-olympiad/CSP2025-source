#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, lc[505];
	long long ans=1, n0 = 0;
	string s;
	cin>>n>>m;
	cin>>s;
	for (int i = 0; i < n; i++)
	{
		cin>>lc[i];
		if(lc[i] == 0){
			n0 ++;
		}
	}
	
	//cout<<endl<<n0<<endl<<endl;
	
	
	if(n - n0 + 1 == m && n0){
		
		for (int i = 1; i <= m-1; i++)
		{
			if(ans > 998244353){
				ans %= 998244353;
			}
			ans *= i;
		}
		ans = ans * n0;
	}else{
		ll num=1;
		int mm = m;
		if(n0){
			mm --;
		}
		for (int i = 1; i <= mm; i++)
		{
			if(ans > 998244353){
				ans %= 998244353;
			}
			ans *= i;
		}
		
		for (int i = 1; i <= n-mm-n0; i++)
		{
			if(num > 998244353){
				num %= 998244353;
			}
			num *= i;
		}
		//ans %= 998244353;
		ans *= num;
		
		ans += n0 * ans % 998244353;
	}
	
	
	cout<<(ans % 998244353);
	
	return 0;
}
