#include<bits/stdc++.h>
using namespace std;
int a[5010];
int vis[5010];
int n;
int mod=998244353;
long long rp=0;
void dfs(int k,int s,int last){
	if(k==s+1){
		int num=0,sum=0,x=0;
		for(int i=1;i<=n;++i){
			if(vis[i]){
				if(sum==s-1){
					x=a[i];
					break;
				}
				num+=a[i];
				sum++;
			}
		}
		if(num>x){
			rp++;
			rp=rp%mod; 
		}
		return ;
	}
	for(int i=last;i<=n;++i){
		vis[i]=true;
		dfs(k+1,s,i+1);
		vis[i]=false;
	}
	return ;
}
void planb(){
	for(int i=3;i<=n-1;i++){
		int cheng[5010];
		int chu[5010];
		int k=1;
		for(int j=n;j>=n-i+1;j--){
			cheng[k]=j;
			k++;
		}
		k=1;
		for(int j=1;j<=i;j++){
			chu[k]=j;
			k++;
		}
		for(int j=1;j<=i;j++){
			for(int ac=1;ac<=i;ac++){
				if(cheng[ac]%chu[j]==0){
					cheng[ac]/=chu[j];
					break;
				}
			}
		}
		long long ak=1;
		for(int j=1;j<=i;j++){
			ak=(ak*cheng[j])%mod;
		}
		rp=(rp+ak)%mod;
	}
	cout<<(rp+1)%mod;
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n;
	int ff=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			ff=false;
		}
	}
	if(ff&&n>20){
		planb();
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		dfs(1,i,1);
	}
	cout<<rp;
	return 0;
}
//10:20 end part 1 score:40?
//10:50 end part 2 score:40+24?
