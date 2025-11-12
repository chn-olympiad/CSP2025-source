#include<bits/stdc++.h>
using namespace std;
int a[5002];
unsigned long long ans=0;
//long long num=1;
long long kpow(int mi){
	if(mi==1) return 2;
	if(mi==0) return 1;
	if(mi%2==0){
		return kpow(mi/2)%998244353*kpow(mi/2)%998244353;
	}
	else{
		return 2*kpow(mi/2)%998244353*kpow(mi/2)%998244353;
	}
}
void dfs(int floor,int maxx,int cnt){
	if(cnt>maxx){
//		for(int i=floor;i>=1;i--){
//			num=num*2%998244353;
//		}
		ans=(ans+kpow(floor)%998244353)%998244353;
		//num=1;
		return ;
	}
	if(floor==0) return ;
	dfs(floor-1,maxx,cnt+a[floor]);
	dfs(floor-1,maxx,cnt);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);//排序 
	if(a[n]==1&&n>20){//特殊情况 
		//cout<<"s"<<endl;
		for(int i=3;i<=n;i++){//枚举最大值 
			dfs(i-1,2,1);
			//cout<<ans<<endl;
		}
		cout<<ans;
		return 0;
	}
	for(int i=3;i<=n;i++){//枚举最大值 
		dfs(i-1,a[i]*2,a[i]);
		//cout<<ans<<endl;
	}
	cout<<ans;
	return 0;
} 