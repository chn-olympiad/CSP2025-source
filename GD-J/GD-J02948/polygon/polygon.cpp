#include<iostream>
#include<algorithm>
using namespace std;
long long n,a[10010],ans,sum;
void dfs(long long now,long long sum,long long maxn){
	if (now==n+1){
		if (sum>2*maxn){
			ans++;
			ans%=998244353;
		}
		return ;
	}
	dfs(now+1,sum+a[now],max(maxn,a[now]));
	dfs(now+1,sum,maxn);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for (int i=1;i<=n;i++){
		cin >>a[i];
		sum+=a[i];
	}
	if (sum==n){
		for (int j=3;j<=n;j++){
			long long res=1,w=n,tmp=1;
			for (int i=1;i<=j;i++){
				res*=w;
				w--;
				tmp*=i;
			}
			ans+=res/tmp;
			ans%=998244353;
		}
		cout <<ans;
	}else{
		dfs(1,0,0);
		cout <<ans;
	}
	return 0;
}
