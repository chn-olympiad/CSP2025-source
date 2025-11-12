#include<bits/stdc++.h>
using namespace std;
int n,m,c[501];
string a;
long long s=1;
int main(){
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=n;i>=m;i--)
		s=(s*i)%998244353;
	cout<<s;
	return 0;
}
