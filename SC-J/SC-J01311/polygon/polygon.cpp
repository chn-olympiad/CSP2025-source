#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[5010];
int answer;
int f[10010];//f[i]:有f[i]个大于等于i的组合 
void dfs(int cnt,int ans,int maxx){
	if(cnt==n+1){
		if(ans>maxx*2) answer=(answer+1)%998244353;
		return;
	}
	dfs(cnt+1,ans+a[cnt],max(maxx,a[cnt]));
	dfs(cnt+1,ans,maxx);
}
bool is_A(){
	for(int i=1;i<=n;i++){
		if(a[i]!=1) return 0;
	}
	return 1;
}
int get_pow(int x,int y){
	if(y==1) return x;
	if(y==0) return 1;
	int mi=get_pow(x,y/2);
	if(y%2==0) return mi*mi%998244353;
	return mi*mi%998244353*x%998244353;
}
void A(){
	for(int i=3;i<=n;i++){
		answer=((answer+get_pow(2,i-1))%998244353+998244353-i%998244353)%998244353;
	}
	cout<<answer;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(is_A()){
		A();
		return 0;
	}
//	if(n<=20){
		dfs(1,0,0);
		cout<<answer;
		return 0;
//	}
//	f[0]=3;
//	f[a[1]+a[2]]=1;
//	for(int i=a[2]+1;i<=a[1]+a[2];i++) f[i]=1;
//	f[a[2]]=2;
//	for(int i=a[1]+1;i<=a[2];i++) f[i]=2;
//	f[a[1]]=3;
//	for(int i=3;i<=n;i++){
//		for(int j=0;j<=a[n]+1;j++){
//			cout<<f[j]<<' ';
//		}
//		cout<<endl;
//		answer=(answer+f[a[i]+1])%998244353;
//		for(int j=a[i];j>=0;j--){
//			f[j+a[i]]=(f[j+a[i]]*f[j])%998244353;
//		}
//		for(int j=0;j<a[i];j++){
//			f[j]=(f[j]*2%998244353+1)%998244353;
//		}
//		for(int j=0;j<=a[n]+1;j++){
//			cout<<f[j]<<' ';
//		}
//		cout<<endl<<endl;
//	}
//	cout<<answer;
//	return 0;
}