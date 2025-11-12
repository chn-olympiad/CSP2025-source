#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,c[101],ans=0;
int bb[101],a[101];
void dfs(int x){
	if(x==n+1){
		int sum=0,anss=0;
		for(int i=1;i<=n;++i)
		if(s[i]=='0'){
			++sum;
		}else if(sum>=c[a[i]])++sum;
		else ++anss;
		if(anss>=m)++ans;
		return ;
	}
	for(int i=1;i<=n;++i)
	if(!bb[i]){
		bb[i]=1;
		a[x]=i;
		dfs(x+1);
		bb[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;s=" "+s;
	for(int i=1;i<=n;++i)cin>>c[i];
	dfs(1);
	cout<<ans;
}
