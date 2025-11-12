#include<bits/stdc++.h>
using namespace std;

const int P = 998244353;
int n,a[6000],maxa;
long long ans;

void dfs(int x,int y,int z){
	if(x>n){
		if(z>y*2){
			ans++;
			ans%=P;
		}
		return;
	}
	dfs(x+1,y,z);
	dfs(x+1,max(y,a[x]),z+a[x]);
} 

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxa=max(maxa,a[i]);
	} 
	if(maxa==1){
		for(int i=3;i<=n;i++){
			long long sum=1;
			for(int j=n,k=1;k<=i;j--,k++){
				sum=sum*j/k;
			}
			ans+=sum;
			ans%=P;
		}
		printf("%d",ans);
		return 0;
	} 
	dfs(1,0,0);
	printf("%d",ans);
	return 0;
} 
