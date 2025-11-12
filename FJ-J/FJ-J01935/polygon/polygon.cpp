#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int mod=998244353;
int n;
int ans;
int a[1000005];
int s[1000005];
int g[1000005];
int maxn;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	s[0]=1;
	s[1]=1;
	for(int i=2;i<=n;i++){
		s[i]=s[i-1];
		s[i]*=i;
		s[i]%=mod;
//		cout<<s[i]<<endl;
	}
	for(int i=3;i<=n;i++){
//		cout<<i<<endl;
		int fl,fr;
		fl=s[n]/s[n-i];
		fr=s[i];
//		cout<<fl<<" "<<fr<<endl;
		ans+=fl/fr;
//		cout<<s[n]/s[i]/2<<" "<<i<<endl; 
		ans%=mod;
	}
	cout<<ans%mod;
	return 0;
}

