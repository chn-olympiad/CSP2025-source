#include<bits/stdc++.h>
#define int long long

using namespace std;

const int SIZN = 550;
const int mod = 998244353;

int n,m;
char s[SIZN];
map<int,int> ni;
set<int> st;
int A(int s,int k){
	int num = 1;
	for(int i = s ; i > (s - k) ; i--){
//		cout << num << '\n';
		num *= i;
		num %= mod;
	}
	return num;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> (s + 1);
	for(int i = 1 ; i <= n ; i++){
		int num;
		cin >> num;
		ni[num]++;
		st.insert(num);
	}
	cout << A(n,m); 
	return 0;
}
