#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans;
void dfs(int k,int vis[],int now,int maxx,int summ){

//	cout<<"visÊý×é:";
//	for(int i=1;i<=n;i++){
//		cout<<vis[i]<<" ";
//	}
//	cout<<endl;
	if(now==n-1){
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				if(summ+a[i]>=2*maxx){
					ans++;
				}
//				cout<<"now:"<<now<<" k:"<<k<<" sum:"<<summ<<" max:"<<maxx<<endl;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
//			cout<<now<<" "<<k<<endl;
			vis[i]=1;
			dfs(k,vis,now+1,max(maxx,a[i]),summ+a[i]);
			vis[i]=0;
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3){
		sort(a+1,a+4);
		if(a[3]<a[1]+a[2])cout<<1;
		else cout<<0;
		return 0;
	}
	else{
		ans=0;
		for(int i=1;i<=n;i++){
			int vis[5005];
			memset(vis,0,sizeof(vis));

			dfs(i,vis,0,0,0);
//			cout<<i<<endl;
		}
		cout<<ans%998244353;
		return 0;
	}
	return 0;
}
