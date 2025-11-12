#include<bits/stdc++.h>
using namespace std;
long long n,m,c=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1,t;i<=m;i++){
		cin>>t;
	}
	n=1;
	for(int i=1;i<=m;i++){
		n*=i;
		n%=998244353;
	}
	cout<<(n*c)%998244353;
	return 0;
}

