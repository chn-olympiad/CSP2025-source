#include<bits/stdc++.h>
using namespace std;
int n,m;
unsigned long long N=1,M=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	 cin>>n>>m;
	for(int i=1;i<=n;i++){
		N*=i;
	}
	for(int i=1;i<=m;i++){
		M*=i;
	}
	cout<<(N/M)%998244353<<endl;
	return 0;
}
