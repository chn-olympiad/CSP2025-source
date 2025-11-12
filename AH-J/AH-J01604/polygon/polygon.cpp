#include<bits/stdc++.h>
using namespace std;
int d[1000000];
int n;

int dfs(int ans,int b)
{
	int i=b;
	ans+=d[i];
	if(ans>d[i])ans++;
	i++;
if(b>=n)return ans;
return dfs(ans,b+1);}
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)
{
cin>>d[i];
}
int ak=0;
for(int i=1;i<=n;i++)
{
	dfs(ak,i);
}
return 0;
}
