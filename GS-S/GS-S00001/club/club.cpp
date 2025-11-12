#include<bits/stdc++.h>
int t;
struct mt{
	int id;
	int anum,bnum,cnum;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin>>t;
	while(t--){
		int n,l,e;
		std::cin>>n;
		int a,b,c;
		for(int i=1;i<=n;i++){
			std::cin>>a>>b>>c;
			l=std::max(a,std::max(b,c));
			e+=l;
		}
		std::cout<<e<<"\n";
	}
	return 0;
}
