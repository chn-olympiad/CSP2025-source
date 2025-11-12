#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string que[2],pl[200005][2];
int check(string s1,string s2)
{
	if(que[0].size()<s1.size())return 0;
	if(que[0].size()==1)
	{
		if(que[0][0]==s1[0]&&que[1][0]==s2[0])return 1;
		else return 0;
	}
	for(unsigned i=0;i+s1.size()-1<que[0].size();i++)
	{
		if(que[0][i]==s1[0])
		{
			bool f=1;
			for(unsigned j=i+1;j-i<s1.size();j++)
			{
				if(que[0][j]!=s1[j-i]||que[1][j]!=s2[j-i])
				{
					f=0;
					break;
				}
			}
			if(f==1)
			{
				bool g=1;
				for(unsigned j=i+s1.size();j<que[0].size();j++)
				{
					if(que[0][j]!=que[1][j])
					{
						g=0;
						break;
					}
				}
				if(g==1)
				{
					//cout<<s1<<' '<<s2<<endl;
					return 1;
				}
			}
		}
		if(que[0][i]!=que[1][i])break;
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>pl[i][0]>>pl[i][1];
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		cin>>que[0]>>que[1];
		for(int j=1;j<=n;j++)
		{
			ans+=check(pl[j][0],pl[j][1]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
