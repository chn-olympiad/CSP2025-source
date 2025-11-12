#include<bits/stdc++.h>
using namespace std;
const long long MAXN=5e3+5,mod=998244353;
long long n,a[MAXN],ans=0;
void dfs(long long x,long long cnt,long long num,long long maxn,bool flag){
	if(cnt>=3 && num>2*maxn && flag)ans++,flag=0;//,ans%=mod,cout<<x<<' '<<cnt<<' '<<num<<' '<<maxn<<endl;
	if(x>n) return ;
	dfs(x+1,cnt,num,maxn,flag);
	dfs(x+1,cnt+1,num+a[x],max(maxn,a[x]),1);
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		dfs(1,0,0,0,1);
		cout<<ans;
	}
	else{
		ans=0;
		for(long long i=3;i<=n;i++){
			long long m=1,mm=1;
			for(long long j=n;j>=n-i+1;j--) m*=j;
			for(long long j=1;j<=i;j++) mm*=i;
			ans+=m/mm;
		}
		cout<<ans;
	}
	return 0;
}
//大概要爆零了 J组都AK不了还学啥 
//luogu @f_XY
