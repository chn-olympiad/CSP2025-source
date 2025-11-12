#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
int n,q;
string s[200005][2];
string s1,s2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	while(q)
	{
		cin>>s1>>s2;
		if(s1.length()!=s2.length())
		{
			cout<<0<<"\n";
			q--;
			continue;
		}
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			int p=0,q1=0;
			for(int j=0;j<s1.length();j++)
			{
				p=j,q1=0;
				while(s[i][0][q1]==s1[p]&&p<s1.length())p++,q1++;
				if(q1==s[i][0].length())
				{
					string temp=s1;
					int l=0;
					for(int k=p-q1;k<p;k++)temp[k]=s[i][1][l++];
					if(temp==s2)sum++;
				}
			}
			
			
		}
		cout<<sum<<"\n";
		
		
		
		
		q--;
	}
	
	//10pts(?)
	return 0;
 } 
