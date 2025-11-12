#include<bits/stdc++.h>
using namespace std;
int n,a[5005],cnt;
void dfs(int x,int sum,int _max){
	if(x>n){
		if(sum>_max*2)cnt++;
		return ;
	}
	dfs(x+1,sum+a[x],max(_max,a[x]));
	dfs(x+1,sum,_max);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    dfs(1,0,0);
	printf("%d",cnt);
	return 0;
}
