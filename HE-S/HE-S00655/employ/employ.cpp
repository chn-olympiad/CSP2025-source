#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 30;
int s[maxn];
int c[maxn];
int p[maxn];
int n, m;
inline bool check(){
	int cnt = 0,res = 0;
	for(int i = 1;i <= n;i++){
		if(s[i] == 0){
			cnt++;
		}
		if(s[i] == 1){
			if(cnt >= c[p[i]]) cnt++;
			else res++;
		}
	}
	return res>=m;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string str;
	cin>>str;
	for(int i = 1;i <= n;i++){
		if(str[i-1] == '0') s[i] = 0;
		else s[i] = 1;
		p[i] = i;
	}
	for(int i = 1;i <= n;i++){
		cin>>c[i];
	}
	int ans = 0;
	do{
		if(check()){
			ans++;
		}
	}
	while(next_permutation(p+1,p+n+1));
	cout<<ans<<endl;
	return 0;
}
/*
++RP bie gua fen
*/
/*
3 2
101
1 1 2
*/
