#include <bits/stdc++.h>
using namespace std;
long long N;
int a[5010];
long long ans=0;
bool flag[5010]={0};
void dfs(int x,int n,int z,int k){
	if(k==N){
		ans%=998244353;
		return ;
	}
	for(long long i=n+1;i<=N;i++){
		if(flag[i]!=1){
			if(x+a[i]>(max(a[i],z))*2){
				flag[i]=1;
				ans++;
				dfs(x+a[i],i,max(a[i],z),k+1);
				flag[i]=0;
			}
			else {
				flag[i]=1;
				dfs(x+a[i],i,max(a[i],z),k+1);
				flag[i]=0;
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>N;
	for(long long i=1;i<=N;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+N);
	if(a[N]==1){
		for(long long i=3;i<=N;i++){
			long long o=1,u=N,v=1,l=1;
			for(long long j=1;j<=i;j++){
				o*=u;
				u--;
				v*=l;
				l++;
			}
			ans+=(o/v);
			ans%=998244353; 
		}
		cout<<ans;
		return 0;
	}
	for(long long i=1;i<=N;i++){
		for(long long j=i+1;j<=N;j++){
			flag[i]=1;flag[j]=1;
			dfs(a[i]+a[j],j,max(a[i],a[j]),2);
			flag[j]=0;
		}
		flag[i]=0;
	}
	cout<<ans%998244353;
	return 0;
}
