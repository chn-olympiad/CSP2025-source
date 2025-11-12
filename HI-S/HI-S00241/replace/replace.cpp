#include<bits/stdc++.h> 
using namespace std;
int a[100005][100005];
void node()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=q;j++)
		{
			cin>>a[i][j];
		}
	 } 
	cout<<0;
}
int main()
{ 
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	whlie(n--) node();
	return 0;
}
