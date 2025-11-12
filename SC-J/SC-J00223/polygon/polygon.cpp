#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[5005];
int n,c;

void dfs(int i,int sum){
	for(int j=i+1;j<n;j++){
		if(sum+a[j]>a[j]*2){
			c++;
			c%=998244353;
		}
		dfs(j,sum+a[j]);
	}
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		dfs(i,a[i]);
	}
	printf("%d",c);
	return 0;
}