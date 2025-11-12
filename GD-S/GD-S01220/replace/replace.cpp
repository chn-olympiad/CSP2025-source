#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,q;
string s[4][N],t[4];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[1][i]>>s[2][i];
	}
	for(int j=1;j<=q;j++)//输入问题 
	{
		int num=0;
		cin>>t[1]>>t[2];
//		cout<<t[1];
		if(t[1].size()!=t[2].size())
		{
			cout<<0<<endl;
			continue;
		}
//		shuangzhizheng
		int q1,q2;
		bool qq=1;
		for(int i=1;i<=n;i++)//判断每个s 
		{
			if(t[1].size() < s[1][i].size())
				continue;//t[1],s[1][i]
			qq=0;
			
			for(int z=1;z<=1+t[1].size()-s[1][i].size();z++)//按位判断 
			{
				string s1;
				s1=t[1][i];
				bool qqq=1;
				if(t[1][z]==s[1][i][z])
				{
					for(int q=0;q<s[1][i].size();q++)
					{
						if(t[1][z+q]==s[1][i][z+q] && 
						t[2][z+q]==s[2][i][z+q])
						{
							s1[z+q]=s[2][i][z+q];
							continue;
						}
						else
						{
							qqq=0;
							break;
						}
							
					}
				}
				else qqq=0;
				if(qqq==1 && s1 ==t[2])
				{
					num++;
				}
			}
		}
		if(qq)cout<<0<<endl; 
		else cout<<num<<endl;
	}
	return 0;
}
