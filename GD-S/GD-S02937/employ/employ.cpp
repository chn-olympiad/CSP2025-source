#include<bits/stdc++.h>
using namespace std;
const long long Mod=998244353;
long long n,m,a[510],ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		ans=(ans*i)%Mod;
	}
	cout<<ans;
	return 0;
}
