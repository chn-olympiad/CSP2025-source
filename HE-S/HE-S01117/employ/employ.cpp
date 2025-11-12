#include<bits/stdc++.h>
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;std::cin>>n>>m;
	long long mul=1;
	for(long long i=1;i<=n;i++){
		mul*=i;	mul%=998244353;
	}
	cout<<mul<<'\n';
	return 0;
}

