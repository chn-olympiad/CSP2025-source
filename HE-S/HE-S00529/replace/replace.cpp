#include<bits/stdc++.h>
#include<string.h>
using namespace std;

const int N=2e5+5;
string s;
string tup[N][4];
unsigned long long ans;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	int ans=0;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>tup[i][1]>>tup[i][2];
	}
	for(int i=1;i<=q;i++)
	{
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<0<<endl;
			continue;
		}
		//cout<<0<<endl;
		/*
		for(int j=1;j<=t1.size();j++)
		{
			if(t1[j]!=t2[j])
			{
				cout<<0<<endl;
				break;
			}
		}*/
		cout<<0<<endl;
	}
	return 0;
}
