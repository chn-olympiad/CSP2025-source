#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	cin>>n;
	long long p=1;
	for(int i=1;i<=n;i++){
		p=p*i% 998244353;
	}
	cout<<p;
} 
