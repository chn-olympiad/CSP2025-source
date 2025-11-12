#include<bits/stdc++.h>
using namespace std;
long long a,ans=1,n,m;
long long const N=998244353;
string c;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>c;
	for(long long i=1;i<=n;i++){
		cin>>a;
	}
	for(long long i=1;i<=n;i++)ans=(ans*i)%N;
	cout<<ans;
	return 0;
}
