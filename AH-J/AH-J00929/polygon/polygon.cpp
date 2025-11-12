#include<bits/stdc++.h>
using namespace std;
const int m=998244353;
int a[5005],s[5005],n,ans;
inline void dfs(int x,int y,int z){
	if(x==n+1)return;
	if(z+1>=3 and y+a[x]>a[x]*2)ans=(ans+1)%m;
	dfs(x+1,y+a[x],z+1);
	dfs(x+1,y,z);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	dfs(1,0,0);
	printf("%d\n",ans);
}
