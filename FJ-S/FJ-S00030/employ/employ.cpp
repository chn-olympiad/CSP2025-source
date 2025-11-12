#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M=998244353;

ll ans=1;
int n,m,c[1007];
string s;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=2;i<=n;i++){
		ans*=i;
		ans%=M;
		//cout<<i<<':'<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
