#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10,MOD=998244353; 
int n,k,ans;
int a[N];
int mxx=-1;
int q_j(int x){//求阶乘 xx
	int cnt=x,ans=1;
	while(cnt>1){
		ans=ans*cnt%MOD;
		cnt--;
	} 
	return ans%MOD;
} 
int q_c(int x,int y){//排列组合C y
	int py=q_j(y);
	int px1=q_j(x),px2=q_j(y-x);
	return py/px1/px2%MOD;
}
void dfs(int x,int maxx,int sum,int num){
	if(x>n) return ;
	int maxx1=max(maxx,a[x]);
	int sum1=sum+a[x];
	int num1=num+1;
	if(sum1>2*maxx1&&num1>=3){
		ans=(ans+1)%MOD;
	}
	dfs(x+1,maxx1,sum1,num1);
	dfs(x+1,maxx,sum,num);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mxx=max(mxx,a[i]);
	}
	if(mxx==1){
		for(int i=3;i<=n;i++){
			ans=(ans+q_c(i,n))%MOD;
		}
		cout<<ans;
		return 0;
	}else{
		//cout<<maxx;
		dfs(1,0,0,0);
		cout<<ans;
		return 0;
	}
	return 0; 
}
