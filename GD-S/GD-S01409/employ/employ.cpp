#include<bits/stdc++.h>
using namespace std;
string s;
long long n,m,c[1000],ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		ans=ans*i%998244353;
	}
	cout<<ans;
	return 0;
}
