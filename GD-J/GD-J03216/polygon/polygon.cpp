#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],ans[N],b;
bool q[N];
void dfs(int k,int x,int y){
	if(k==0){
		int maxx=0,sum=0;
		for(int i=1;i<=x;i++) sum+=ans[i];
		for(int i=1;i<=x;i++) maxx=max(maxx,ans[i]);
		if(sum>maxx*2) b=(b+1)%998244353;
		return ;
	}
	for(int i=y;i<=n;i++){
		if(q[i]!=0) continue;
		ans[k]=a[i];
		q[i]=1;
		dfs(k-1,x,i+1);
		q[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=3;i<=n;i++){
		dfs(i,i,1);
	}
	cout<<b%998244353;
	return 0;
} 
