#include <bits/stdc++.h>
using namespace std;
int n,m;
int a,r,f=0;
int main()
{
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	for(int i=2;i<=n*m;i++)
	{
		scanf("%d",&a);
		if(a>r)f++;
	}
	int lie=f/n+1,h=(f+1)%n;
	if(h==0)h=n;
	if(lie%2==0)h=n-h+1;
	cout<<lie<<" "<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

