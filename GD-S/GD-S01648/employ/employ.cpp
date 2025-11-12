#include<iostream>
#include<string>
using namespace std;
#define ll (long long)
int n,m,many[19],chose[18];
string a;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	int M=0;
	for(int i=1;i<=n;i++)cin>>many[i],chose[i]=1,M+=int(many[i]==0);
	if(n-M>=m)cout<<(ll(ll(1)<<n)%998244353);
	else
	cout<<0;
}
