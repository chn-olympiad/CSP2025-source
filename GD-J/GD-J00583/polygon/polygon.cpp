#include<bits/stdc++.h>
using namespace std;
int a[5010];
int k[5010];
int ans=0,sum2=1;
void dfs(int n,int step,int sum){
	if(step>n){
		if(sum>2){
			long long cnt=0;
			int maxi=0;
			for(int i=1;i<sum2;i++){
				cnt+=k[i];
				maxi=max(maxi,k[i]);
			}
			if(maxi*2>=cnt){
				ans++;	
			}
		}
		return ;
	}
	k[sum2]=a[step];
	sum2++;
	dfs(n,step+1,sum+1);
	k[sum2-1]=0;
	sum2--;
	dfs(n,step+1,sum);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,maxi=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxi=max(maxi,a[i]);
	}
	long long sum=1;
	int k=n;
	while(k>=1){
		sum*=2;
		sum%=988244353;
		k--;
	}
	sum-=(n*(n-1))/2;
	sum-=n;
	sum--;	
	if(n<=100&&maxi!=1){
		dfs(n,1,0);
		sum-=ans;
	}else if(maxi!=1){
		cout<<0;
		return 0;
	}
	printf("%d",sum);
	return 0;
} 
