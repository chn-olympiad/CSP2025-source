#include<bits/stdc++.h>
using namespace std;
int n,m,i,t,a;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;t=n;
	for(i=1;i<=n;i++)
	{cin>>a;if(a==0)t--;}
	if(t<m){cout<<0;return 0;}
	for(a=i=1;i<=n;i++)
	a=(a*i)%998244353;
	cout<<a;
	return 0;
}
