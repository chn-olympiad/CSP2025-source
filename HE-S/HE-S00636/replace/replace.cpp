#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string s[10001][2],t[10001][2];
int n,q,st2,ed1,ans=0;
int main()
{
	freopen("replace.in","r",stdin);
	froopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t[i][0]>>t[i][1]; 
		for(int j=0;j<t[i][0].length();j++)
		{
		    for(int k=1;k<n;k++)
		    {
		    	string temp;
		        bool flag=true;
		        ed1=j;
		        st2=j+s[k][0].length();
		    	for(int l=j;l<j+s[k][0].length();l++)
		    	{
		    		if(t[i][0][l]!=s[k][0][l-j])
		    	    {
		    			flag=false;
		    			break;
					}
				}
				if(flag)
				{
					for(int l=0;l<ed1;l++)temp+=t[i][0][l];
					temp+=s[k][1];
					for(int l=st2;l<=n;l++)temp+=t[i][0][l];
					if(temp==t[i][1])ans++;
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
