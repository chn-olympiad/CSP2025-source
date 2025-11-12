#include<bits/stdc++.h>
using namespace std;
using in = long long;
in n,m,ans = 0,a[501];
string s;
void A(in f,in sh,in t){
	if(f > n){
		ans = t % 998244353;
		return;
	}
	for(in i = 1;i <= n;i ++){
		if(s[f-1] == '0')
			A(f+1,sh+1,t);
		else if(a[i] <= sh)
			A(f+1,sh+1,t);
		else{
			A(f+1,sh,t+1);
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(in i = 1;i <= n;i ++)
		cin >> a[i];
	A(1,0,0);
	cout << ans;
	return 0;
}
