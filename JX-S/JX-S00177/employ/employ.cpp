#include<bits/stdc++.h>
using namespace std;
const long long N=998244353;
long long n,m,a[1000],ans=1,c[1000];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(long long i=1;i<=n;i++){
		cin>>c[i];
		ans*=i;
	}
	cout<<ans%N;
	return 0;
}
