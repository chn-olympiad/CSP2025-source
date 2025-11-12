#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	unsigned long long a,b;
	cin>>a>>b;
	unsigned long long c=1;
	for(int i=1;i<=a;++i){
		c*=i;
		c%=998244353;
	}
	cout<<c;
	return 0;
}
