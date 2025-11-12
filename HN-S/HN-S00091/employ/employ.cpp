#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n;
	cin>>m>>n;
	string s;
	cin>>s;
	for(int i=1;i<=m;i++)
	{
		int k;
		cin>>k;
	}
	int sum=1;
	for(int i=1;i<=n;i++)
	{
		sum=sum*i%998244343;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
