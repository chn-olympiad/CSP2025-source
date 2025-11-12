#include<bits/stdc++.h>
using namespace std;
int n,m;
string s1[200005],s2[200005],s3,s4;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=m;i++)
	{
		int ans=0;
		cin>>s3>>s4;
		if(s3.size()!=s4.size())
		{
			cout<<0<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			string ss3=s3,ss4=s4;
			int fd1,fd2,f=0;
			while(fd1!=-1&&fd2!=-1)
			{
				fd1=s3.find(s1[i],f);
				fd2=s4.find(s2[i],f);
				for(int j=fd1;j<=fd1+s1[i].size();j++)
				{
					ss3[j]=s2[i][j];
				}
				if(ss3==ss4)ans++,f=fd1;
				if(ss3!=ss4)f=min(fd1,fd2);
				f++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
