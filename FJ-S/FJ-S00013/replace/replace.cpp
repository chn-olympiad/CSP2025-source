#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
long long ans;
string s[N][2],t[3];
unordered_map<int,int> _next[N];
void getnext(int x)
{
	int j=0;
	_next[x][0]=-1;
	for(int i=1;i<s[x][0].size();i++)
	{
		if(s[x][0][i]==s[x][0][j]) _next[x][i]=j+1,j++;
		else
		{
			if(j==0) _next[x][i]=0,j=0;
			else j=_next[x][j-1],i--;
		}
	}
}
void KMP(int x)
{
	for(int i=0,j=0;i<t[0].size();)
	{
		if(s[x][0][j]==t[0][i]) i++,j++;
		else if(j) j=_next[x][j-1];
		else i++;
		if(j==s[x][0].size())
		{
			for(int k=i-j,l=0;k<i;k++,l++)
				t[0][k]=s[x][1][l];
			if(t[0]==t[1]) ans++;
			for(int k=i-j;k<i;k++)
				t[0][k]=t[2][k];
			j=0;
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1],getnext(i);
	while(q--)
	{
		cin>>t[0]>>t[1];t[2]=t[0];
		ans=0;
		for(int i=1;i<=n;i++) KMP(i);
		cout<<ans<<endl;
	}
	return 0;
}
