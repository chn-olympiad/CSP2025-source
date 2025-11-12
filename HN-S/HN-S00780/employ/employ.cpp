#include<bits/stdc++.h>
using namespace std;
int n,m,h,a[555];
void dfs(int l,int k){
	if(k>n) return;
	if(k>=m) h++;
	for(int i=l+1;i<=n;i++) dfs(i,k++);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) dfs(i,1);
	printf("%d",h);
	return 0;
}
