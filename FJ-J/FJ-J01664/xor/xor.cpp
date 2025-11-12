#include<bits/stdc++.h>
using namespace std;
long long a[1000000]={};
int n,k,ans=0;
int e(int i,int j){
	int f=1,m,q=1,ii[100],jj[100],r[100]={},y=1,t=0;
	while(q*2<i){
		q=q*2;
		f++;
	}
	m=f;
	while(i>0){
		ii[f]=i/q;
		i=i-i/q*q;
		q=q/2;
		f--;
	}
	f=1;
	q=1;
	while(q*2<j) {
		q=q*2;
		f++;
	}
	m=max(m,f);
	while(j>0){
		jj[f]=j/q;
		j=j-j/q*q;
		q=q/2;
		f--;
	}
	for(int p=1;p<=m;p++){
		if(ii[p]!=jj[p]){
			r[p]=1;
		}
	}
	for(int p=1;p<=m;p++){
		for(int w=2;w<=p;w++){
			y=y*2;
		}
		t=t+r[p]*y;
		y=1;
	}
	return t;
}
void dfs(int b,int c,int d){
	if(a[c]==k){
		d++;
		for(int u=c+1;u<=n;u++){
			dfs(a[u],u,d);
		}
		return;
	}
	if(c==n){
		if(b==k) d++;
		ans=max(ans,d);
		return;
	}
	if(b==k){
		d++;
		for(int u=c+1;u<=n;u++){
			dfs(a[u],u,d);
		}
		return;
	}
	for(int u=c+1;u<=n;u++){
		int s=e(b,a[u]);
		dfs(s,u,d);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
		}
	}
	dfs(a[1],1,0);
	cout<<ans;
}
