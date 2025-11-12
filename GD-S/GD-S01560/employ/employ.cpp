#include<bits/stdc++.h>
#define int long long
using namespace std;
char s1[1145140]; 
int a[1145140],s = 0,p,n;
int ans = 1;
int zuhe(int a,int b){//a个里选b个 
	int res = 1;
	for(int i = a;i >= a - b + 1;i--){
		res = ((res % 998244353) * i) % 998244353;
	}
	return res;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>p;
	cin>>s1;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i] != 0){
			s++;
		}
	}
	if(n == p){
		bool q = 1;
		int ans = 1;
		for(int i = 1;i <= n;i++){
			if(s1[i] == '0' || a[i] == 0){
				q = 0;
			}
		}
		if(q == 0){
			cout<<0<<endl;
		}else{
			for(int i = 1;i <= n;i++){
				ans *= i % 998244353;
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	int ans = 0;
	for(int k = p;k <= s;k++){
		ans = (ans + (zuhe(k,p) % 998244353)) % 998244353;
	}
	cout<<ans % 998244353<<endl;
	return 0;
}
/*
这是最后一战
一切都已经结束了
他们投降了
战争结束了
我的OI生涯也结束了
在我刚开始学OI时
我总是嘲笑那些遗憾离场的选手
那时我自命不凡
而现在
我炸的那么彻底 
		——2025.11.1.18.22.53
*/ 
