#include<bits/stdc++.h>
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL),std::cout.tie(NULL);
	std::random_device seed;
	std::mt19937_64 rd(seed()*seed()%(seed()*2));
	int n,q;
	std::cin>>n>>q;
	while(q--){
		long long r=rd()%(1ll*n*n);
		long long s=labs(rd()%(1ll*n*n*(r?r:1)));
		std::cout<<(s>n*n?0:s)<<'\n';
	}
}
void null(){
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
//	froepen("replace.in","r",stdin);
//	froepen("replace.out","w",stdout);
//	freopen("replace.in","r",stdin);
//	freopen("replace.ans","w",stdout);
//	freopen("replace4.in","r",stdin);
//	freopen("replace4.out","w",stdout);
//	freopen(" replace.in","r",stdin);
//	freopen(" replace.out","w",stdout);
//	luogu UID 1754409
}
