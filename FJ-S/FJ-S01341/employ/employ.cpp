#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n,i;
	long long sum=1;
	string s;
	cin>>n>>m>>s;
	for(i=1;i<=n;i++){
		cin>>m;
		sum*=i;
	}
	cout<<sum%998244353;
}