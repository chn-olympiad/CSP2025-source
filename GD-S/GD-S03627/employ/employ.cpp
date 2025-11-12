#include<bits/stdc++.h>
using namespace std;
int n,m,c[20],ans;
string s;
bool v[15];
void dfs(int mg,int g,int d)
{
	if(d>n){
		if(g>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!v[i])
		{
			v[i]=true;
			if(c[i]>mg&&s[d-1]=='1')
			{
				dfs(mg,g+1,d+1);
			}
			else dfs(mg+1,g,d+1);
			v[i]=false;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	getchar();
	getline(cin,s);
	int sum=0;
	for(int i=0;i<s.size();i++) if(s[i]=='1') sum++;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	 } 
	if(n<=12)
	{
		dfs(0,0,1);
		printf("%d",ans);
	}
	else if(sum<=18)
	{
		if(m>18){
			printf("0");
		}
	} 
	return 0;
}
