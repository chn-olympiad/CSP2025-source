#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
typedef long long ll;
ll n,m,ans=1,ans1=1,ans2=1,c[N];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		ans=(ans*i)%998244353;
	}
	for(int i=1;i<=m;i++){
		ans1=(ans1*i)%998244353;
	}
	for(int i=1;i<=n-m;i++){
		ans2=(ans2*i)%998244353;
	}
	cout<<ans/((ans1*ans2)%998244353);

	return 0;
}
