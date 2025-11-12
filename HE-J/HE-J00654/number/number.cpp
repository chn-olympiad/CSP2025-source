#include<bits/stdc++.h>
using namespace std;
int const N = 1e4 + 5;
long long l,ans = 0,t;
string a;
int num[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> a;
	l = a.size();
	for(int i = 0;i < l;i++){
		if(a[i] >= '0' and a[i] <= '9'){
			num[t] = a[i] - '0';
			t++;
		}
	}
	sort(num,num + t);
	for(int i = t - 1;i >= 0;i--){
		ans = ans * 10 + num[i];
	}
	cout << ans;
	return 0;
}
/*
290es1q0
*/
