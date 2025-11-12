#include<bits/stdc++.h>
using namespace std;
int n,q,t;
string s[2][200005],t1,t2,sx;
void solve()
{
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>s[0][i]>>s[1][i];
	}
	for(int i=0;i<=q;i++)
	{
		cin>>t1>>t2;
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<t1.length()-s[0][j].length();k++)
			{
				if(s[0][j][k]==t1[0])
				{
					bool x=1;
					for(int l=0;l<s[0][j].length();l++)
					{
						if(t1[k+l]!=s[0][j][l])
						{
							x=0;
							break;
						}
					}
					if(x)
					{
						for(int l=0;l<k;l++)
						{
							sx+=t1[l];
						}
						sx+=s[0][j];
						for(int l=k+s[0][j].length();l<t1.length();l++)
						{
							sx+=t1[l];
						}
						if(sx==t2)
						{
							t++;
						}
					}
				}
			}			
		}
		cout<<t;
		t=0; 
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
