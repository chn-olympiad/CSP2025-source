#include<bits/stdc++.h>
using namespace std;
int n,q,cnt;
string s1[114514],s2[114514],s3[114514],s4[114514],wqw;
void dfs(int step,string temp,string ans)
{
	if(temp==ans)
	{
		cnt++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<temp.size()-s1[i].size()+1;j++)
		{
			if(temp.substr(j,j+s1[i].size())==s2[i])
			{
				string wqw;
				for(int k=0;k<temp.size()-s1[i].size()+s2[i].size();k++)
				if(k>=j&&k<j+s2[i].size())
				wqw+=s2[i][k-j]; 
				else
				wqw+=temp[k-s1[i].size()+s2[i].size()];
				dfs(step,wqw,ans);
			}
		}
	 } 
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
cin>>n>>q;
for(int  i=1;i<=n;i++)
cin>>s1[i]>>s2[i];
for(int i=1;i<=q;i++)
{
	cin>>s3[i]>>s4[i];
	cnt=0;
	//dfs(0,s3[i],s4[i]);
	cout<<cnt<<endl;
}
return 0;
}


