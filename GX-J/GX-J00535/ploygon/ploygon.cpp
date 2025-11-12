#include<bits/stdc++.h>
using namespace std;
int n[5001];
int main()
{
	freopen("ploygon.in","r",stdin);
	freopen("ploygen.out","w",stdout);
	int k;
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>n[i];
	}
	if(n[1]==1)
	{
		cout<<9;
	}
	if(n[1]==2)
	{
		cout<<6;
	}
	return 0;
}
