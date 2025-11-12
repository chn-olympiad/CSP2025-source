#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	int b;
	int c;
	int num;
}a[100005];
int n,t;
int dfs(int pos,int ai,int bi,int ci){
	if(pos==n+1) return 0;
	int x=0;
	if(ai<n/2) x=max(dfs(pos+1,ai+1,bi,ci)+a[pos].a,x);
	if(bi<n/2) x=max(dfs(pos+1,ai,bi+1,ci)+a[pos].b,x);
	if(ci<n/2) x=max(dfs(pos+1,ai,bi,ci+1)+a[pos].c,x);
	return x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		cout<<dfs(1,0,0,0)<<endl;
		memset(a,0,sizeof(a));
	}
	
	return 0;
}
