#include<bits/stdc++.h>
using namespace std;
int a[600],n,m,v[600],b[600],ans;
string s;
int dfs(int x){
	if(x==n+1){
		int l=0,t=0;
		for(int i=1;i<=n;i++){
			cout<<b[i]<<" ";
			if(s[i]=='1'&&a[b[i]]>l) t++;
			else l++;
			if(t==m) break;
		}
		if(t>=m) ans++;
		cout<<"\n";
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
//		cout<<i<<"\n\n";
			v[i]=1;
			b[x]=i;
//			cout<<b[i]<<" ";
			dfs(x+1);
			b[i]=0;
			v[i]=0;
		}
	}
	return 0;
}
int main(){
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
} 
/*
3 2
101
1 1 2
*/
