#include<bits/stdc++.h>
using namespace std;
int n,q;
string x,y;
struct eyz{
	string a,b;
}s[200050]; 
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		cin>>s[i].a>>s[i].b;
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		int m=x.size(),ans=0;
		for(int j=1;j<=n;j++)
			if(x==s[i].a&&y==s[i].b)
				ans++;
		printf("%d\n",ans);	
	}
	return 0;
}

