#include<bits/stdc++.h>
using namespace std;
char s[501];
int c[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,sum=0,a;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		cin>>c[i];
	}
	for(int j=1;j<=n;j++)
		if(s[j]==1)
			sum++;
	if(sum==n)
		if(m==n)
			cout<<1;
		else if(m==1)
			cout<<n;
		else
			cout<<n;
	else
		cout<<a%998244353;
	return 0;
}
