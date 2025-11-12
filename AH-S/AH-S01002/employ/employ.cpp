#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int n,m,c[505];
long long ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	cout<<n<<' '<<m<<endl<<s<<' '<<' '<<213456412545435<<endl;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n-m;i++) ans=ans*i%p;
	cout<<ans<<endl;
	return 0;
}

