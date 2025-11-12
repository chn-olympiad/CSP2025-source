#include<bits/stdc++.h>
using namespace std;
int n;
const int N=5e3+10;
int a[N],ans;
void dfs(int c,int maxx,int sum,int m){
	if(sum>(maxx*2) and (m+1>2)){
		ans++;
		ans%=998244353;
	}
	if(c<n){
		for(int i=c+1;i<=n;i++){
			dfs(i,max(maxx,a[i]),sum+a[i],m+1);
		}
	}
	else return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dfs(i,a[i],a[i],1);
	}
	printf("%d",ans);
	return 0;
}
