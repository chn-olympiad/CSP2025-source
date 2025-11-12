#include<bits/stdc++.h>
using namespace std;
long long n,m,i,c[1000],t;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==1)
		t++;
	}
	cout<<t%998244353;
	return 0;
}
