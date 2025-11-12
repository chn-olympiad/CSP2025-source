#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 505;
const int mod = 998244353;
int n, m, c[N], n2;
ll ans = 1;
ll ans2 = 1;
string s;
void main2(){
	for(int i = 1; i <= n; i ++){
		ans = (ans * i)  % mod;
	}
}
int main(){
	freopen("employ.in","r", stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d", &n, &m);
	int f = 0;
	cin>>s;
	for(int i = 0; i < n; i ++){
		if(s[i] != '1') f = 1;
	}
	n2 = n;
	for(int i = 1; i <= n; i ++){
		scanf("%d", &c[i]);
		if(c[i] == 0) {
			i --;
			n --;
		}
	}
	//cout<<n<<endl;
	if(!f) {
		main2();
	}
	if(m == 0) cout<<0<<endl;
	cout<<ans;
	return 0;
}
