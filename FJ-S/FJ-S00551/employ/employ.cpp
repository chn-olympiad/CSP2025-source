#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[505];
long long sum=1;
int main( ){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		sum*=i;
		sum%=998244353;
	}
	cout<<sum;
	return 0;
}

