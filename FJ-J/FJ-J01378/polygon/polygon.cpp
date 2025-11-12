#include<bits/stdc++.h>
using namespace std;
int n,m=0,ans=0;
int a[5005];
map<string,bool> mp;
void dfs(int ge,int big,int he,int w,string s)
{
//	cout<<w<<" ";
	if(ge>=3&&big*2<he&&he>0&&!mp[s])ans++;
	if(w>n)return ;
	mp[s]=1;
	dfs(ge,big,he,w+1,s);
	dfs(ge+1,max(big,a[w]),he+a[w],w+1,s+to_string(w)+" ");
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);	
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(0,0,0,1,"");
	cout<<ans;
	return 0;
}
