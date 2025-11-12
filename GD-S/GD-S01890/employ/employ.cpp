#include<bits/stdc++.h>
#define int long long
const int Mod= 998244353,N=600;
using namespace std;

int n,m,ans=1,a[N],sum;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]!=0) sum++;
	}
	for(int i=1;i<=sum;i++){
		(ans*=i)%=Mod;
	}
	for(int i=1;i<=n-sum;i++){
		(ans*=sum)%=Mod;
	}
	cout<<ans;
	return 0;
}

