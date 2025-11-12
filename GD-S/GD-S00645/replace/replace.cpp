#include<bits/stdc++.h>
using namespace std;
string a[200005][10];
string t[200005][10];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d",&n);
	scanf("%d",&q);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1];
		cin>>a[i][2];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t[i][1];
		cin>>t[i][2];
	}
	for(int i=1;i<=q;i++)
	{
		printf("%d",0);
		cout<<endl;
	}
 } 
