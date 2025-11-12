#include <bits/stdc++.h>
using namespace std;

struct Dict
{
	string a,b;
};

Dict dict[200005];

string slip(string s,int i,int j)
{
	string s1 = "";
	for(;i<=j;i++)s1+=s[i];
	return s1;
}
int isin(string s1,int n)
{
	for(int i = 1;i<=n;i++)
	{
		if(dict[i].a==s1)return i;
	}
	return 0;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i = 1;i<=n;i++)cin>>dict[i].a>>dict[i].b;
	for(int t = 1;t<=q;t++)
	{
		string s1,s2;
		cin>>s1>>s2;
		int cnt = 0;
		for(int i = 0;i<s1.size();i++)
		{
			for(int j = i;j<s1.size();j++)
			{
				int tmp =isin(slip(s1,i,j),n);
				if(tmp>0)
				{
					string stmp = slip(s1,0,i-1)+dict[tmp].b+slip(s1,j+1,s1.size()-1);
					if(stmp==s2)cnt++;
				}
				
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
