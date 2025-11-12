#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=1;
string a;
long long w[600];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		sum*=i;
		sum%=998244353;
	}
	cout<<sum;
	return 0;
}


