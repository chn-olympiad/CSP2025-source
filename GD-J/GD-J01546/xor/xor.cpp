#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=105;
int n,m,tmp,x,y,k,ans;
int a[N];
void dfs(int x,int l,int res,int cnt){
	cout<<x<<" "<<l<<" "<<res<<" "<<cnt<<endl;
	if(x==n+1){
		if(l && res==k) cnt++;
		ans=max(ans,cnt);
		return;
	}
	if(l){
		if(res!=k) dfs(x+1,1,res^a[x],cnt);
		else{
			dfs(x+1,0,0,cnt+1);
			dfs(x+1,1,a[x],cnt+1);
		}
	}
	else{
		dfs(x+1,1,a[x],cnt);
		dfs(x+1,0,0,cnt);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(1,1,a[1],0);
	dfs(1,0,0,0);
	printf("%d",ans);
	return 0;
}
