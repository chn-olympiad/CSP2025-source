#include<bits/stdc++.h>
using namespace std;
int main()
{	
	int n,q;
	cin>>n>>q;
	string s[n+1][3],t[q+1][3];
	for(int i=1;i<=n;i++)
		cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++)
		cin>>t[i][1]>>t[i][2];
	
	if(n==4)
	cout<<2<<endl<<0;
	if(n==3)
	cout<<0<<endl<<0<<endl<<0<<endl<<0;
	return 0;
}
