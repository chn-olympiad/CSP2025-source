#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	int a[n+1],ans=1,jl=1;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=n-1;i>=m;i--){
		jl=(jl*(i+1)/(n-i))%998244353;
		ans=(ans+jl)%998244353;
	}
	cout<<ans;
}
