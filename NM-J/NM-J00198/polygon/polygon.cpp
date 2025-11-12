#include<bits/stdc++.h>
using namespace std;
int n,a[5050];
long long ans=0;
struct node{
	int w,s;
}b[5050];
bool cmp(int a,int b){
	return a<=b;
}
bool cmp1(node a,node b){
	return a.w>b.w;
}
void dfs(int w,int g,int s,int z,int l){
	if(s==0){
		if(l*2<z){
			ans=(ans+1)%998244353;
		}
		return;
	}
	for(int j=g+1;j<=min(b[w].s,s);j++){
		dfs(w,j,s-1,z+b[w].w,l=max(l,b[w].w));
	}
	if(b[w+1].w==0)return;
	dfs(w+1,1,s,z,l);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int r=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		r=max(r,a[i]);
	}
	if(r==1){
		cout<<(n-2)%998244353;
		return 0;
	}
	if(n==3){
		if(max(a[1],max(a[2],a[3]))*2<a[1]+a[2]+a[3])cout<<1;
		else cout<<0;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	int idx;
	for(int i=1;i<=n;i++){
		idx=a[i];
		b[idx].w=idx;
		b[idx].s++;
	}
	sort(b,b+n+1,cmp1);
	for(int i=3;i<=n;i++){
		dfs(1,1,i,0,0);
	}
	cout<<ans;
	return 0;
}
