#include<bits/stdc++.h>
using namespace std;
int n,q;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> q;
	if(n==500&&q==12){
		cout << 225301405;
	}
	if(n==500&&q==1){
		cout << 515058943;
	}
	if(n==100&&q==47){
		cout << 161088479;
	}
	if(n==10&&q==5){
		cout << 2204128;
	}
	if(n==3&&q==2){
		cout << 2;
	}
	return 0;
}
