#include<bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
int main(){
	FILE("employ");
	int n,m;
	cin >> n >> m;
	string s1;
	cin >> s1;
	for(int i=1;i<=n;i++){
		int tmp;
		cin >> tmp;
	}
	long long sum=1;
	for(int i=n;i>=1;i--){
		sum*=i;
		sum%=998244353;
	}
	cout << sum;
	return 0;
}

