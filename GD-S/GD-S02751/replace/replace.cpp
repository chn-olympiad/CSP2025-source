#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=2e5+10;
string s[N][3],t[3];
int l1[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,Q,ans;
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
		l1[i]=s[i][1].length();
	}
	while(Q--)
	{
		ans=0;
		cin>>t[1]>>t[2];
		int l2=t[1].length();
		for(int i=1;i<=n;i++)
			for(int j=0;j+l1[i]<=l2;j++)
			{
				string y=t[1].substr(j,l1[i]);
				if(y==s[i][1])
				{
					string x=t[1].substr(0,j),z=t[1].substr(j+l1[i],l2-j-l1[i]),tt;
					tt=x+s[i][2]+z;
					if(tt==t[2]) ans++;
				}
			}
		printf("%d\n",ans);
	}
	return 0;
}
