#include<bits/stdc++.h>
using namespace std;
int n,a[25],ans;
void dfs(int i,int num,int sum,int mx){
    if(i>n){
	    if(num>=3&&mx*2<sum) ans++;
	    return ;
	}
	dfs(i+1,num,sum,mx);
	dfs(i+1,num+1,sum+a[i],max(mx,a[i]));
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n<=20) dfs(1,0,0,0);
	cout<<ans;
    return 0;
}
