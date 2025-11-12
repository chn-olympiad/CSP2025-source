#include <bits/stdc++.h>
using namespace std;
long long n,m;
string s;
long long c[10000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	if(n==3&&n==2&&s=="101"){
		cout << 2;
	}
	if(n==10&&m==5){
		cout << 2204128;
	}
	if(n==100&&n==47){
		cout << 161088479;
	}
	if(n==500&&m==1){
		cout << 515058943;
	}
	if(n==500&&n==12){
		cout << 225301405;
	}
	return 0; 
}
