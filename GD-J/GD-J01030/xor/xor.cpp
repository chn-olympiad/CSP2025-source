#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
void dfs(int p,int s){
	if(p>n){printf("%d",s);exit(0);}
	for(int i=p,t=0;i<=n;i++){
		t^=a[i];
		if(t==k)dfs(i+1,s+1);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}dfs(1,0);
	return 0;
}
