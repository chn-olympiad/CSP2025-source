#include <bits/stdc++.h>
using namespace std;
int n,a[5005],ans=0;
bool fg[5005]={};
void dfs(int a1,int a2,int a3,int a4){
    if(a2>=3&&a1>2*a3){
    	ans++;
	}
	if(a2==n){
		return;
	}
	for(int i=a4+1;i<=n;++i){
		if(!fg[i]){
			fg[i]=1;
			dfs(a1+a[i],a2+1,max(a[i],a3),i);
			fg[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;++i){
		fg[i]=1;
		dfs(a[i],1,a[i],i);
		fg[i]=0;
	}
	printf("%d",ans);
	return 0;
}
