#include<bits/stdc++.h>
using namespace std;
long long n,k,v=0;
long long a[500010];

struct p{
	long long a,b;
}c[500010];
int cmp(p a,p b){
	return a.b<b.b;
}
void dfs(long long m,long long j){
	if(j+m-1>=n){
		return;
	}
	long long o=a[j];
	for(long long i=j+1;i<j+m;i++){
		o^=a[i];
	}
	if(o==k){
		c[v].a=j;
		c[v].b=j+m-1;
		v++;
	}
	dfs(m,j+1);
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)dfs(i,0);
	sort(c,c+v,cmp);
	long long o=-1,ans=0;
	for(long long i=0;i<v;i++){
		if(c[i].a>o){
			ans++;
			o=c[i].b;
		}
	}
	cout<<ans;
	return 0;
}