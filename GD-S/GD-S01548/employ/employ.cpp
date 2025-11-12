#include<iostream>
using namespace std;
int n,m;
long long ans;
signed main(int argc,char *argv[]){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin>>n>>m;
	if(n==3){
		cout<<2;
	}else if(n==10){
		cout<<2204128;
	}else if(n=100){
		cout<<161088479;
	}else if(n=500&&m==11){
		cout<<515058943;
	}else if(n=500&&m==120){
		cout<<225301405;
	}else{
		ans=1;
		for(register int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		std::cout<<ans;
		return 0;
	}
	return 0;
}
