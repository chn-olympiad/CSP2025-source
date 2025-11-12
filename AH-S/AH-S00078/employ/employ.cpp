#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
ll n,sum=1,c[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>s;
	for(ll i=1;i<=n;i++) cin>>c[i];
	for(ll i=2;i<=n;i++){
		sum*=i;
		sum%=998244353;
	}
	cout<<sum;
	return 0;
}