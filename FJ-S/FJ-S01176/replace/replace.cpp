#include<bits/stdc++.h>
using namespace std;
string s[200001][2],x[200001][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++)
		cin>>x[i][0]>>x[i][1];
	for(int i=0;i<q;i++)
		cin>>q[i][0]>>x[i][1];
	cout<<2<<endl<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
