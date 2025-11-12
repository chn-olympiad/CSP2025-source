#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];
	int o[1000],k[1000];
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int h,l,t=1,e=1,g;
	cin>>h>>l;
	for(int i=0;i<h*l;i++) cin>>o[i];
	int x[4]={0,0,+1,0};
	int y[4]={0,+1,0,+1};
	for(int i=0;i<=h*l;i++)
	{
		t=t+x[i];
		e=e+y[i];
		a[t][e]=o[i];
	}
	for(int i=1;i<=l;i++)
	{
		for(int j=1;j<=h;j++)
		{
				if(g==a[i][j]) cout<<j<<" "<<i;
		}
	}

	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
