#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int a[N];int cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string str;cin >> str;
	for(int i=0;i<str.size();++i)
		if(str[i] >= '0' && str[i] <= '9')
			a[cnt++] = str[i]-'0';
	sort(a,a+cnt);
	if(a[--cnt] == 0) cout << 0;
	else{
		for(int i=cnt;i>=0;--i)
			cout << a[i];
	}
	return 0;
}
