#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int a[N],b[N];
bool vis[N];
int n,ans=0;
void dfs(int x,int y){
	if(x==y){
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<y;j++){
//				if()
//			}
//		} 
		int sum=0;
		for(int i=1;i<y;i++){
			sum+=b[i];
//			cout<<b[i]<<' ';
		}
//		cout<<endl<<(sum>2*b[y-1])<<endl;
		if(sum>2*b[y-1]){
			ans++;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			if(a[i]<b[x-1]) continue;
			b[x]=a[i];
			vis[i]=0;
			dfs(x+1,y);
			vis[i]=1;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	if(n<3){
		cout<<0;
	}else if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		for(int i=1;i<=n;i++) vis[i]=1;//每一个数都没用过 
		for(int i=4;i<=n+1;i++){
			dfs(1,i);
		}
		cout<<ans;
	}
	return 0;
}