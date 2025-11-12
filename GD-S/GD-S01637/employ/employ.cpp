#include<bits/stdc++.h>
using namespace std;
const int N = 510,M = 510;
long long n,m;
string s;
int c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i++)cin >> c[i];
	if(n==m){
		for(int i = 0;i < n;i++){
			if(s[i]=='0'){
				cout << 0;
				return 0;
			}
 		}
 		cout << 1;
 		return 0;
	}
	else{
		long long res = 1;
		while(n>0){
			res*=n;
			n--;
			res%=998244353;
		}
		cout << res;
	}
	return 0;
}

