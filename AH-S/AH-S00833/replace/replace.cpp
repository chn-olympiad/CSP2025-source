#include<iostream>
using namespace std;
const int N=2e5+5;
string s[N][2],qu[N][2];
int n,q,cnt;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++)
		cin>>qu[i][0]>>qu[i][1];
	for(int i=1;i<=q;i++)
	{
		cnt=0;
		int x=qu[i][0].size();
		for(int j=0;j<x;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(s[k][0][0]==qu[i][0][j])
				{
					if(s[k][0][1]==qu[i][1][j])
						cnt++;
				}
			}
		}
		if(cnt==1) cnt*=2;
		else if(cnt==4) cnt=0;
		printf("%d\n",cnt);
	}
	return 0;
}
