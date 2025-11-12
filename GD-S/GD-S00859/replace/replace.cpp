#include<bits/stdc++.h>
using namespace std;
string s[200005],st[20005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	int n,q;
	cin>>n>>q;
	for(int i = 1;i<=n;i++)
	{
		cin>>s[i]>>st[i];
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		int len = t1.size();
		if(t2.size()!= len)
		{
			cout<<0<<endl;
			continue;
		}
		int cnt=0;
		for(int i = 1;i<=n;i++)
		{
			for(int j = 0;j<len;j++)
			{
				bool f = true;
				if(t1[j] == s[i][0] && j+ s[i].size() <=len)
				{
					for(int k = 0;k<s[i].size();k++)
					{
						if(t1[j+k] != s[i][k] || t2[j+k] != st[i][k]) 
						{
							f=false;
							break;
						}
					
					}
					if(f==false) break;
					for(int k = 0;k<j;k++)
					{
						if(t1[k] != t2[k])
						{
							f=false;
							break;
						}
					}
				
					if(f==false) break;
					for(int k = j+s[i].size();k<len;k++)
					{
						if(t1[k]!=t2[k])
						{
							f=false;
							break;
						}
					}
					if(f==true) cnt++;
				} 
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
 } 
 
