#include <bits/stdc++.h>
using namespace std;
int t = 998244353;
int m,n;
string s;
unsigned int c[500];
int main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
//	t=101;

	unsigned long long ans=1;
	for(long long i=1;i<=n-1;i++){
		ans=ans%t;
		cout<<ans<<endl;
		ans*=i;
		cout<<ans<<endl<<endl;
	}
	ans %=t;
	cout<<endl<<ans;
	return 0;
}
