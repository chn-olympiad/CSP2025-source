#include<iostream>
using namespace std;
const int MOD=998244353;
int n;
int a[5010];
int ans=0;
void dfs(int idx,int cnt,int sum,int Max){
	if(idx>n){
		if(cnt>=3&&sum>2*Max){
			ans=(ans+1)%MOD;
		}
		return;
	}
	dfs(idx+1,cnt,sum,Max);
	dfs(idx+1,cnt+1,sum+a[idx],max(Max,a[idx]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0<<endl;
	}else if(n==3){
		if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3])){
			cout<<1<<endl;
		}else{
			cout<<0<<endl;
		}
	}else if(n<=20){
		dfs(1,0,0,0);
		cout<<ans<<endl;
	}else{
		int mul=1;
		for(int i=1;i<=n;i++){
			mul=(mul*2)%MOD;
		}
		cout<<(mul+MOD-1-n-n*(n-1)/2)%MOD<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
