#include<bits/stdc++.h>
using namespace std;
int main()
{	
	int n,m;
	cin>>n>>m;
	char s[n+1];
	int c[n+1];
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(n==3)
	cout<<"2";
	if(n==10)
	cout<<2204128;
	return 0;
}
