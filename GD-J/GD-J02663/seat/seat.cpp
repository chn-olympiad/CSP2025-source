#include<bits/stdc++.h>
using namespace std;
int b;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,o=0,nl,ml;
	cin>>m>>n;
	cin>>a;
	for(int i=2;i<=n*m;i++)
	{
		cin>>b;
		if(b>a)
		{
			o++;
		}
	}
	nl=o/m;
	ml=o-nl*m;
	ml++;
	nl++;
	if(nl%2==0)
	{
		ml=m-ml+1;
	}
	cout<<nl<<" "<<ml<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
