#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,num;
	cin>>n>>m;
	num=1;
	for(long long i=2;i<=n;i++){
		num*=i;num%=998244353;
	}
	cout<<num;
	return 0;
}
