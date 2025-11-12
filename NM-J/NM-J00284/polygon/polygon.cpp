#include<bits/stdc++.h>
using namespace std;
int p[100];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int i,n,s;
	cin>>n;
	for(i=1;i<=3;i++)
	{
		cin>>p[i];
		if(s<p[i]) s=p[i];
	}
	if(p[1]+p[2]+p[3]>2*s) cout<<1;
	else cout<<0;
	return 0;
}
