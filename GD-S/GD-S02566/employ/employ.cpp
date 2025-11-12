#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,m;
string s;
long long c[510];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) n--;
	}
	//cout<<n<<endl;
	long long ans=1;
	for(int i=n;i>=m;i--){
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
