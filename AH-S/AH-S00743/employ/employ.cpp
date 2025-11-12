#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long cum=1,a,b;
	long long c;
	cin>>a>>b;
	c=b;
	string s;
	cin>>s;
	for(long long i=1;i<=b;i++){
		long long x;
		cin>>x;
		if(x==0) c--;
	}
	for(long long i=1;i<=c;i++){
		cum=cum*i%998244353;
	}
	cout<<cum;
	return 0;
}
