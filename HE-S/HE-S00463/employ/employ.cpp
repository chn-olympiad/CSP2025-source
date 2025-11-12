#include<iostream>
#include<cstring>
using namespace std;
const int mod=998244353;
int n,m,can;
string s;
long long ans;
int main(){
	freopen("employ3.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	can=n;
	cin>>s;
	for(int i=1;i<=n;i++){
		int p;
		cin>>p;
		if(!p){
			can--;
		}
	}
	ans=1;
//	cout<<can<<endl;
	for(int i=can;i>=1;i--){
		//cout<<ans*i<<endl;
		//cout<<(ans*i)%mod<<"***"<<endl;
		ans=(ans*i)%mod;
	}
	cout<<ans;
	return 0;
}
