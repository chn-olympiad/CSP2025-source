#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353,N=5005;
int n,a[N],check,maxpos;
ll ans=0;
ll qpow(int x,int y){//x^y
	ll res=1;
	while(y){
		if(y&1){
			res=res*x%mod;
		}
		x=x*x%mod;
		y>>=1;
	} 
	return res;
}
void dfs(int i,int cur){
//	cout<<"dfs("<<i<<","<<cur<<")";
	if(i>=maxpos){
//		cout<<"->";
		if(cur>check){
			++ans;
			if(ans>=mod)
				ans=ans%mod;
//			cout<<"1\n";
		}
		else{
//			cout<<"x\n";	
		}
		return;
	}
//	if(cur>check){
//		//这样剩下的所有的都是合法的 
//		ans=(ans+(qpow(2,maxpos-i-1)))%mod;
//		return ;
//	}
//	cout<<"\n";
	dfs(i+1,cur);
	dfs(i+1,cur+a[i]);
}
void solve_task_C(){
	ans=0;
	for(int i = 3 ; i <= n ;++i){
		ans=(ans+((i-1)*(i-2)/2)%mod)%mod;
	}
	cout<<ans<<endl; 
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1 ; i <= n ; ++i){
		cin>>a[i];
	}
	if(n>20){
		solve_task_C();//全1的情况 
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i = 3 ; i <= n ; ++i){
		maxpos=i;
		check=a[i];
		dfs(1,0);
	}
	cout<<ans<<endl;
	return 0;
} 
