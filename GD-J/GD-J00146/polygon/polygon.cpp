#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int n,a[N],ans,num;
bool vis[N];
void dfs(int step,int maxn,int tot,int front){
	if(step<0){
		if(tot>2*maxn){
			cout<<maxn<<" "<<tot<<" "<<front<<endl;
			ans++;
			return ;
		}
	}
	for(int i=1;i<=n-step+1;i++){
		if(a[i]<maxn) continue;
		if(!vis[i]){
			int g=max(maxn,a[i]);
			vis[i]=1;
			dfs(step-1,g,tot+=a[i],a[i]);
		}
		vis[i]=0;
	}
}
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
	}else if(n==3){
		int d=0,f=0;
		for(int i=1;i<=n;i++){
			d=max(a[i],d);
			f+=a[i];
		}
		if(f>d*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		sort(a+1,a+n+1);
		ans=0;
		for(int i=3;i<=n;i++){
			dfs(i,0,0,0);
		}
		cout<<ans;
	}
	return 0;
}
