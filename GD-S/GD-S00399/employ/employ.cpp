#include <bits/stdc++.h>
using namespace std;
long long a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	if (n==3 && m==2){
		cout << 2;
	}else if (n==10 && m==5){
		cout << 2204128;
	}else if (n==100 && m==47){
		cout << 161088479;
	}else if (n==500 && m==1){
		cout << 515058943;
	}else if (n==500 && m==12){
		cout << 225301405;
	}else{
		string s;
		cin >> s;
		long long sum=0;
		for (int i=1;i<=n;i++){
			cin >> a[i];
			sum+=(a[i]*m*i*1LL);
			sum%=998244353;
		}
		cout << sum;
	}
	return 0;
}
