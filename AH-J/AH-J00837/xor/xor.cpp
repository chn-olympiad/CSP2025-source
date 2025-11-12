#include<bits/stdc++.h>
using namespace std;
int n;
bool flag=true;
long long k;
const int N=1e5+5;
long long a[5*N];
int maxn;
void dfs(int now,int ans,int tmp){
	if(now==n+1){
		if(tmp==k) ans++;
		maxn=max(maxn,ans);
		return ;
	}
	if(tmp==-1){
		if(a[now]==k){
			dfs(now+1,ans+1,-1);
		}else{
			dfs(now+1,ans,-1);
			dfs(now+1,ans,a[now]);
		}
	}else{
		if(tmp==k){
			dfs(now,ans+1,-1);
		}else{
			dfs(now+1,ans,tmp^a[now]);
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]>1) flag=false;
	}
	if(flag){
		if(k==0){
			int sum=0,i=1;
			while(i<=n){
				if(a[i]==0){
					sum++;i++;
					continue;
				}
				int now=i+1;
				while(a[now]==a[i]) now++;
				if(now>i+1){
					sum++;
					i=now;
				}else{
					i++;
				}
			}
			printf("%d\n",sum);
		}else if(k==1){
			int sums=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) sums++;
			}
			printf("%d\n",sums);
		}
	}else{
		dfs(1,0,-1);
		printf("%d\n",maxn);
	}
	return 0;
}
