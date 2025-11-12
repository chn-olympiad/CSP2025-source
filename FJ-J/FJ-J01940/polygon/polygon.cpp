#include<bits/stdc++.h>
using namespace std;
long long n,a[5000],u[5000],t[5000],ans,jh;
int is_polygon(){
	long long k=0,max_num=0,s=0;
	for(int i=1;i<=jh;i++){
			k+=a[u[i]];
			max_num=max(max_num,a[u[i]]);
	}
    if(2*max_num<k){
    	return 1;
	}
	return 0;
}
void dfs(int x){
	if(x==0){
		if(is_polygon())ans++;
		return;
	}
	for(int i=u[x+1]+1;i<=n;i++){
		u[x]=i;
		dfs(x-1);
		u[x]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	a[0]=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
    for(int i=3;i<=n;i++){
    	jh=i;
    	dfs(i);
	}
    cout<<ans%998244353;
	return 0;
}
