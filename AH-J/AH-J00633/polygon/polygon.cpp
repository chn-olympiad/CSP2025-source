#include<iostream>
#include<algorithm>
using namespace std;
int n;
int a[5010],ans;
void dfs(int now,int t,int sum,int x,int p){
	if(now==p){
		if(sum>2*x)ans++;
		return;
	}
	for(int i=t+1;i<=n;i++){
		dfs(now+1,i,sum+a[i],a[i],p);
	}
}
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
scanf("%d",&n);
for(int i=1;i<=n;i++)scanf("%d ",&a[i]);
sort(a+1,a+1+n);

for(int k=3;k<=n;k++){
	dfs(0,0,0,0,k);
}
printf("%d",ans);
return 0;
}
