#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> a(n);
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0;i < n;++i)cin >> a[i];
	if(k <= 1){
		int cnt = 0,_cnt = 0;bool f = 0;
		for(int i = 0;i < n;++i){
			if(a[i] == 1)cnt++;
			if(a[i] && a[i - 1] && i != 0 && !f){f = 1;_cnt++;}
			else f = 0;
			}
		if(cnt == n){
			if(k == 0)cout << n/2;
			else cout << n;
			}
		else if(k == 1)cout << cnt;
		else cout << n - cnt + _cnt;
		
		return 0;
		}
	else cout << 0;
	return 0;
}
