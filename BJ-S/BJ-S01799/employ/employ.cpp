#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N =1e6 + 10;
const int M = 998244353;
ll c[N],n,m,q,k,ans;
string s;
ll id[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	s = "%" + s;
	for(int i = 1;i <= n;i ++){
		cin >> c[i];
		id[i] = i;
	}
	do{
		ll cnt,cnt1;
		cnt = cnt1 = 0;
		for(int i = 1;i <= n;i ++){
			if(cnt < c[id[i]] && s[i] == '1') cnt1++;
			if(s[i] == '0'|| cnt >= c[id[i]]) cnt++;
		}
		if(cnt1 >= m){
			ans++;
			ans %= M;
			
		}
		
	}while(next_permutation(id + 1,id + n + 1));
	cout << ans % M;
	return 0;
}
