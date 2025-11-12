#include<bits/stdc++.h>
using namespace std;
int n,A,b,c,a[510],vis[510];
long long ans;
int jiec(int x){
	long long ans=1;
	for(int i=1;i<=x;i++)
		ans*=i;
	return ans;
}
void dfs(int x,int tot,int mm){
	if(x>=3&&tot>2*mm){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=0;
			dfs(i,tot+a[i],max(mm,a[i]));
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		cin>>A>>b>>c;
		if((A+b+c)>2*max(A,max(b,c)))
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)	
		scanf("%d ",&a[i]);
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(i,a[i],a[i]);
		vis[i]=0;
	}
	cout<<ans/jiec(n);
	return 0;
}
