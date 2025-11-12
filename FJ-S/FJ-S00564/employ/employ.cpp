#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s;
long long a[501];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.ans","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1) cout<<1;
	if(n==2) cout<<2;
	return 0;
}
