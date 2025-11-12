#include<bits/stdc++.h>
using namespace std;
int a[100005];
int x[100005];
int n,m;
int ans=0;
int bok[100005];
string s;
int work(){
	int t=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(t>=a[x[i]]||((s[i-1]-'0')==0))t++;
		else cnt++;
	}
	return (cnt>=m);
}
void dfs(int xx){
	if(xx==n+1){
		ans+=work();
		//for(int i=1;i<=n;i++)cout<<x[i]<<" ";
		//cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(bok[i])continue;
		bok[i]=1;
		x[xx]=i;
		dfs(xx+1);
		bok[i]=0;
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1);
	cout<<ans; 
	return 0;
}
