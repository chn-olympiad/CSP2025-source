#include<bits/stdc++.h>
using namespace std;
int a[15][15],c[105];
int main()
{
	freopen("seat.in","r"stdin);
	freopen("seat.out","w"stdout);
	int n,m,p=0,s=1,g=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>c[i];
		p=c[1];
	}
	sort(c+1,c+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		a[s][g]=c[i];
		s++;
		if(s>n)
		{
			s=0;
			g++;
		}
		if(a[s][g]=p)
		{
			cout<<g<<" "<<s;
			break;
		}
	}
	return 0;
}
