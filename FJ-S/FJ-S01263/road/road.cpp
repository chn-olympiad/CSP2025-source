#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,t=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		t+=c;
	}
	cout<<t;
	return 0;
}
/*

RP++ RP++ RP++ RP++ RP++ RP++ RP++ RP++ RP++ RP++ RP++ RP++ RP++ RP++ RP++ RP++ RP++ RP++
*/
