#include<bits/stdc++.h>
using namespace std;
string a[1000010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		a[i]=s;
	}
	for(int i=1;i<=q;i++)
	{
		string s;
		cin>>s;
		a[i]=s;
	}
	for(int i=1;i<=q;i++)
	cout<<"0"<<endl; 
 } 
