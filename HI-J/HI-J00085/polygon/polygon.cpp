#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
bool f[5005];
set <string> ans;
void dfs(int k,string s){
	int zs=0,maxx=0;
	for(int i=0;i<s.size();i++){
		zs+=(s[i]-'0');
		maxx=max(maxx,s[i]-'0');
	}
	if(zs>maxx*2&&s.size()>=3){
		sort(s.begin(),s.end());
		ans.insert(s);
	}
	if(k==n+1){
		return  ;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			char zs=(a[i]+'0');
			dfs(k+1,s+zs);
			f[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,"");
	printf("%d",ans.size());
	
	return 0;
}
