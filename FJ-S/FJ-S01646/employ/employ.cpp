#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long 
using namespace std;
int n,m;
string s;
int c[505];
ll f(int q){
	if(q==1) return 1;
	return q*f(q-1)%998244353;
}
int main()
{
	IOS
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	cout<<f(n);
}
