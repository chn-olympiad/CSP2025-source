#include<bits/stdc++.h>
using namespace std;
int q[5000004][3];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		string s,s1;
		cin>>s>>s1;
		int j=s.find("b");
		int k=s1.find("b");
		if(j!=-1&&k!=-1)
		{
			int m=j-k;
			q[i][0]=m;
			q[i][1]=j;
			q[i][2]=s.length()-j-1;
		}
	}
	int sum=0;
	for(int i=1;i<=m;i++)
	{
		string s,s1;
		cin>>s>>s1;
		if(s.length()!=s1.length())
		{
			cout<<"0"<<endl;
			continue;
		}
		int j=s.find("b");
		int k=s1.find("b");
		int f=s.length();
		if(j==-1||k==-1)
		{
			cout<<"0"<<endl;
			continue;
		}
		else
		{
			sum=0;
			for(int h=1;h<=n;h++)
			{
				if(q[h][0]==j-k&&j>=q[h][1]&&f-j-1>=q[h][2])
				{
					sum++;
				}
			}	
			cout<<sum;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
