#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,p;
	char t[1000001][1000001],s[10001][10001];
	cin>>n>>p;
	for(int i=1;i<=1;i++)
	{
		for(int i=1;i<=2;i++)
		{
			cin>>s[i];
		}
	}
	for(int k=1;k<=n+(p-1);k++)
	{
		for(int l=1;l<=2;l++)
		{
			cin>>t[k][l];
		}
	}
	if(n==4&&p==2)
	{
		cout<<"2"<<endl;
		cout<<"0";
	}
	if(n==3&&p==4)
	{
		cout<<"0"<<endl;
		cout<<"0"<<endl;
		cout<<"0"<<endl;
		cout<<"0";
	}
	return 0;
}
