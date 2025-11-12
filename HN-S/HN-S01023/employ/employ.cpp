#include<bits/stdc++.h>
using namespace std;
const long long M=998244353;
long long n,m,a,ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a;
	}
	for(long long i=1;i<=n;i++){
		ans=(ans*i)%M;
	}
	cout<<ans;
	return 0;
}
