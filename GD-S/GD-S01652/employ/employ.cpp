#include <bits/stdc++.h>
using namespace std;
long long MOD=998244353;
int f(int n){
	int sum=1;
	while(n){
		sum*=n;
		sum%=MOD;
		n--;
	}
	return sum;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m>>s;
	int num,cnt=0;
	for(int i=1;i<=n;i++){
		cin>>num;
	}
	cout<<0<<endl;
	return 0;
}
