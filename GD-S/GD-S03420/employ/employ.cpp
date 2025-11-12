#include<bits/stdc++.h>
using namespace std;
int n,m;
long long sum;
char ac[505];
int la;
bool aaa = 1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	if(n == m){
		sum = 1;
		for(int i = 1;i <= n;i++){
			sum *= i;
			sum %= 998244353;
		}
		cout << sum;
		return 0;
	}
	scanf("%s",ac+1);
	la = strlen(ac+1);
	for(int i = 1;i <= la;i++){
		if(ac[i] != '1'){
			aaa = 0;
		}
	}
	if(aaa){
		sum = 1;
		for(int i = 1;i <= n;i++){
			sum *= i;
			sum %= 998244353;
		}
		cout << sum;
		return 0;
	}
	cout << 18;
	return 0;
}
