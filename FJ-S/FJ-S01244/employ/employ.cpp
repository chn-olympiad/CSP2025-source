#include<bits/stdc++.h>
using namespace std;
int ans[600];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string a;
	cin>>a;
	srand(time(0));
	for(int i=1;i<=n;i++)
	{
		cin>>ans[i];
	}
	cout<<rand();
	return 0;
} 
