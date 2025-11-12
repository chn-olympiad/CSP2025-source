#include<bits/stdc++.h>
using namespace std;

int n,ans;
int a[5001],b[5001];

inline void dfs(int i,int x){
	if(i>=n+1){
		int sum=0,ma=0;
		for(int j=1;j<=n;j++){
			if(b[j]==1){
				sum+=a[j];
				ma=max(ma,a[j]);
			}
		}
		if(sum>ma*2 && x>=3){
			ans++;
		}
		return ;
	}
	b[i]=1;
	dfs(i+1,x+1);
	b[i]=0;
	dfs(i+1,x);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(1,0);
	printf("%d",ans%998%244%353);
}
