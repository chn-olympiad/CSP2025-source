#include<bits/stdc++.h>
using namespace std;
long long a[5005];
int n;
int m1,m2;
unsigned long long f(int cp){
	if(cp == 3){
		m1 = (n - 1) * (n - 2) * n;
		m2 = 6;
	}
	else{
		m1 *= (n - cp + 1);
		m2 *= cp;
		}
	return m1/m2;
}
unsigned long long dfs(int op,long long prep){//suoyin muqianhe
	unsigned long long cnt = 0;
	for(int i = op + 1;i < n;++i){//xiabiao
		if(prep > a[i]){cnt++;}
		cnt += dfs(i,prep+a[i]);
	}
	return cnt;
	}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	unsigned long long cnt = 0;
	cin >> n;
	bool flag = false;
	for(int i = 0;i < n;++i){
		cin >> a[i];
		if(a[i] != 1)flag = true;
		}
		
	if(!flag){
		for(int i = 3;i <= n;++i){
			cnt += f(i);
			}
		cout << cnt % 998244353;
		return 0;
		}
		
	sort(a, a + n);
	for(int i = 0;i < n;++i){
		cnt += dfs(i,a[i]);
		}
	cout << cnt % 998244353;
	return 0;
}
