//Ren5Jie4Di4Ling5%
#include<iostream>
using namespace std;
int main(void){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m>=n){
		cout<<0;
	}else{
		long long ans=1;
		for(int i=2;i<=n;i++){
			ans*=i;
			ans=ans%998244353;
		}
		cout<<ans;
	}return 0;
}
