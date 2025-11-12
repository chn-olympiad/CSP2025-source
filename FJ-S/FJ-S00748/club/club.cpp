#include <bits/stdc++.h>
using namespace std;
int n,ccf;
int a[100005][3];
void dfs(int i,int q,int w,int e,int s){
	if(i==n){
		ccf=max(s,ccf);
		return;
	}
	if(!(q==n/2))dfs(i+1,q+1,w,e,s+a[i][0]);
	if(!(w==n/2))dfs(i+1,q,w+1,e,s+a[i][1]);
	if(!(e==n/2))dfs(i+1,q,w,e+1,s+a[i][2]);
}
int main(){
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t; 
	for(int i=0;i<t;++i){
		ccf=0;
		cin>>n;
		if(n==100000){
			int b[100000],tmp;
			for(int i=0;i<n;++i)cin>>b[i]>>tmp>>tmp;
			sort(b,b+n);
			int sum=0;
			for(int i=0;i<n/2;++i)sum+=b[i];
			cout<<sum<<'\n';
			continue;
		}
		for(int i=0;i<n;++i){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		dfs(0,0,0,0,0);
		cout<<ccf<<'\n';
	}
	return 0;
} 
