#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int m[110];
string s;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(auto x:s)if(isdigit(x))m[x - '0'] ++;
	for(int i = 9;i >= 0;i --){
		if(m[i]){
			while(m[i] --)cout << i;
		}
	}
	return 0;
}

