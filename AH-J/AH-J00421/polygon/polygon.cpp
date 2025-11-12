#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long a[5005];
long long flg[5005];
long long n,cnt,maxn;
long long fun(long long n){
	long long sum=5;
	for(int i=1;i<=n-4;i++){
		sum+=pow(2,i-1)*10+1;
		sum%=mod;
	}return sum;
}void dfs(long long step,long long sum,long long maxn){
	if(step>=3){
		if(sum>maxn*2)cnt++;
		cnt%=mod;
	}for(int i=1;i<=n;i++){
		if(!flg[i]){
			flg[i]=1;
			dfs(step+1,sum+a[i],max(maxn,a[i]));
			flg[i]=0;
		}
	}
}int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}if(maxn==1){
		if(n==3){
			cout<<1;
			return 0;
		}if(n==4){
			cout<<5;
			return 0;
		}cout<<fun(n);
	}else{
		dfs(1ll,0ll,0ll);
		cout<<cnt;
	}
	return 0;
}
