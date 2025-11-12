#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
long long ans;
string s[N][2],t1,t2,x,y,z;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t1>>t2;
		ans=0;
		int l1=t1.size();
		for(int l=0;l<l1;l++)
		{
			for(int i=1;i+l<=l1;i++)
			{
				int j=i+l;
				x="",y="",z="";
				for(int k=1;k<i;k++)
				{
					x=x+t1[k-1];
				}
				for(int k=i;k<=j;k++)
				{
					y=y+t1[k-1];
				}
				for(int k=j+1;k<=l1;k++)
				{
					z=z+t1[k-1];
				}
				for(int k=1;k<=n;k++)
				{
					if(y==s[k][0])
					{
						string ss="";
						ss=ss+x;
						ss=ss+s[k][1];
						ss=ss+z;
						if(ss==t2)
						{
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
 } 
