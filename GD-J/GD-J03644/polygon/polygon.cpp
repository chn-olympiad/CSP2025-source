#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],m,s;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		m=max(m,a[i]);
		s+=a[i];
	}
	if(s>2*m) cout<<"1";
	else cout<<"0";
	return 0;
} 
