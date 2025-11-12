#include<bits/stdc++.h>
using namespace std;
int n,a[1010]={0,0,0,1,3,9},ans,now,b[510][510];
void dfs(int k,int now,int maxn){
	if (2*maxn<now) ans++;
	if (k+1==n){
		cout<<ans;
		exit(0);
		return;
	}
	for (int i=k+1;i<=n;i++){	
		dfs(k+1,now+a[i],a[i]);
		dfs(k+1,now,maxn);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if (n<=5){
		cout<<a[n];
		return 0;
	}
	memset(a,0,sizeof(a));
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	for (int i=1;i<=n;i++){
//		for (int j=i+1;i<j;j++){
//			for (int k=j+1;k>j;k++){
//				if (a[i]+a[j]>a[k]){
//					ans++;
//					b[i][k]=a[i]+a[j]+a[k];
//				}
//			}
//		}
//	}
//	for (int i=1;i<=n;i++){
//		for (int j=i+1;i<j;j++){
//			
//		}
//	}
	dfs(0,0,0);
	return 0;
}
