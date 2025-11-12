#include<bits/stdc++.h>
using namespace std;
int n,m,b[505];
long long mod=998244353,s;
string a;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>a;
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	s=1;
	for(int i=1;i<=n;i++)
	{
		s=s*i%mod;
	}
	cout<<s;
	return 0;
} 
