#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	long long sum=1;
	for(int i=2;i<=n;i++) sum=sum*i%mod;
	cout<<sum;
	return 0;
}

