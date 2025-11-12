#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll P=998244353;
ll n,m,ans=1,tot;
string s;
ll c[1010];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	getchar();
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=n;i>=1;i--){
		ans=(ans*i)%P;
	}
	cout<<ans<<endl;
	return 0;
}
