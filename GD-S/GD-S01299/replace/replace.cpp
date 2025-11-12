#include<bits/stdc++.h>
using namespace std;
long long n,q,js=0;
string a[200005][5],l,r;
void dfs(string s)
{
	if(s==r)
	{
		js++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<n-a[i][1].size()+1;j++)
		{
			bool b=true;
			for(int k=j;k<=j+a[i][1].size()-1;k++)
			{
				if(s[k]!=a[i][1][k-j+1])
				{
					b=false;
					break;
				}
			}
			if(b)
			{
				string t=s;
				for(int k=j;k<=j+a[i][1].size()-1;k++)
					s[k]=a[i][2][k-j+1];
				dfs(t);
			}
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i][1]>>a[i][2];
	while(q--)
	{
		cin>>l>>r;
		dfs(l);
		cout<<js<<endl;
		js=0;
	}
	return 0;
}
