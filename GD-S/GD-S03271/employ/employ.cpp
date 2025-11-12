#include<bits/stdc++.h>
using namespace std;

int n,m;
int c[2010],p[2010];
char s[2010];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1;i<=n;i++) p[i]=i;int cnta=0;
	do
	{
		int cnt=0,pa=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt>=c[p[i]] || s[i]=='0') 
			{
				cnt++;
				continue;
			}
			pa++;
		}
		if(pa==m) cnta++;
	}while(next_permutation(p+1,p+n+1));
	cout<<cnta<<endl;
}
