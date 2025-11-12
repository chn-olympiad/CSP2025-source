#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[1000005];
bool vis[1000005];
int zd,ans;
int cnt=0;
void dfs(int step,int lst){
	if(step>=3+1){
		if(ans>2*zd){
			cnt=(cnt+1)%mod;
		} 
	}
	for(int i=lst+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			zd=a[i];
			ans+=a[i]; 
			dfs(step+1,i);
			ans-=a[i];
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out ","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0);
	cout<<cnt<<"\n";
	return 0;
}