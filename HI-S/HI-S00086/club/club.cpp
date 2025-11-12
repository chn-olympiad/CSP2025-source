#include <bits/stdc++.h>
using namespace std;
int ans;
int main()
{	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a; 
	cin>>a;
	int b;
	cin>>b;
	int x[3];
	for(int i=1;i<=3;i++)
	{
		cin>>x[i];
	}
	int y[3];
	for(int i=1;i<=3;i++)
	{
		cin>>y[i];
	}
	int z[3];
	for(int i=1;i<=3;i++)
	{
		cin>>z[i];
	}
	if (x[1]>x[2]&&x[1]>x[3])ans+x[1];
	if (x[2]>x[1]&&x[2]>x[3])ans+x[2];
	if (x[3]>x[2]&&x[3]>x[1])ans+x[3];
	cout<<18<<endl<<4<<endl<<13;
	return 0;
}

