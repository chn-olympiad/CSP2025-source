#include<bits/stdc++.h>
using namespace std;
long long n,q,sum,b[5],sl[200005][3],tl[200005][3],l[200005],ql[200005];
string s[200005][3],t[200005][3];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
		int j=0;
		while(s[i][1][j]>='a'&&s[i][1][j]<='z')
		{
			if(s[i][1][j]=='b')
			{
				sl[i][1]=j;
			}
			if(s[i][2][j]=='b')
			{
				sl[i][2]=j;
			}
			j++;
		}
		l[i]=j;
	}
	for(int i=1;i<=q;i++)
	{
		sum=0;
		cin>>t[i][1]>>t[i][2];
		int j=0;
		while(t[i][1][j]>='a'&&t[i][1][j]<='z')
		{
			if(t[i][1][j]=='b')
			{
				tl[i][1]=j;
			}
			if(t[i][2][j]=='b')
			{
				tl[i][2]=j;
			}
			j++;
		}
		ql[i]=j;
		for(int j=1;j<=n;j++)
		{
			if(tl[i][1]>=sl[j][1]&&ql[i]-tl[i][1]>=l[j]-sl[j][1]&&tl[i][1]-tl[i][2]==sl[j][1]-sl[j][2])
			{
				sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
