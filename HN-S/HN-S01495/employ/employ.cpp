#include<iostream>
using namespace std;
const int md=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m;
	string s;
	long long ans=1;
	cin>>n>>m>>s;
	int a[10000];
	
	for(int j=1;j<=n;j++){
		ans=(ans*j)%md;
	}
	cout<<ans;
	
	return 0;
}
