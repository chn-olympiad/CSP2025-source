#include<bits/stdc++.h>
using namespace std;
int n,q; 
string s[200050][5];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	while(q--)
	{
		int cnt=0;
		string t1,t2; cin>>t1>>t2;
		for(int i=0;i<=t1.size()-1;i++) 
		{
			for(int j=1;j<=n;j++)
			{
				if(i+s[j][1].size()-1>=t1.size()) continue;
				bool flag=true;
				for(int k=0;k<=s[j][1].size()-1;k++)
				{
					if(t1[i+k]!=s[j][1][k]){flag=false; break;
					}
				}
				if(flag)
				{
					string tt1="";
					if(i>1) tt1=t1.substr(0,i-1);
					string ttt=tt1+s[j][2]+t1.substr(i+s[j][1].size());
					if(ttt==t2) cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
