#include <bits/stdc++.h>
using namespace std;
int chengs[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>chengs[i];
		chengs[i]=-chengs[i];
	}
	int mub=chengs[1];
	int pos=0;
	sort(chengs+1,chengs+1+n*m);
	for(int i=1;i<=n*m;i++)
	{
		if(chengs[i]==mub) pos=i;
	}
	
	int hang,lie;
	lie=(pos-1)/n+1;
	pos=(pos-1)%n;
	pos++;
	if(lie%2==1) hang=pos;
	else hang=n-pos+1;
	cout<<lie<<' '<<hang;
}
