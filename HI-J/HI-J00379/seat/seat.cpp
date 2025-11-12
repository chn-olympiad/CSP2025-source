#include<bits/stdc++.h>
using namespace std;

int n,m,x,y,t=1,ansl,ansh;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m>>x;
	for(int i=2;i<=n*m;i++)
	{
		scanf("%d",&y);
		if(y>x)t++;
	}
	if(t%n!=0)ansl++;
	ansl+=t/n;
	if(ansl%2==1)ansh=t-(ansl-1)*n;
	else ansh=n+1-(t-(ansl-1)*n);
	cout<<ansl<<" "<<ansh;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
