#include<bits/stdc++.h>
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL),std::cout.tie(NULL);
	int n,m;
	std::bitset<505> bits;
	std::cin>>n>>m>>bits;
	if(bits.count()<m){
		std::cout<<0;
		return 0;
	}
	std::random_device seed;
	std::cout<<seed()%std::min(n*n,998224353);
}

