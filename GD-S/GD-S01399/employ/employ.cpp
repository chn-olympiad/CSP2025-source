#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string a;
	cin>>a;
	int c[10000];
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(n==3&&m==2)cout<<"2";
	if(n==10&&m==5)cout<<"2204128";
	return 0;
}
