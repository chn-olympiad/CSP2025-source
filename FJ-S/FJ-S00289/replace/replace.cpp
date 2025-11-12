#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1,s2;
string s3,s4;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
	}
	for(int j=1;j<=q;j++)
	{
		cin>>s3>>s4;
	}
	for(int j=1;j<=q;j++)
	{
		if((s3==s1 && s4==s2)||(s3==s2 && s4==s1))
		{
			cout<<"2"<<endl;
		}
		cout<<"0"<<endl;
	}
	return 0;
}
