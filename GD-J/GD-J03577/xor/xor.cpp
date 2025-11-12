#include<bits/stdc++.h>
using namespace std;
int a[500010];
int n,k;
int solve(int l,int r){
	int sum=0;
	int x=a[l];
	if(x==k){
		int q=1+solve(l+1,r);
	}
	for(int i=l+1;i<=r;i++){
		x=x^a[i];
		if(x==k){
			int p=1+solve(i+1,r);
		}
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d",a[i]);
	}
	printf("%d",solve(1,n));
	return 0;
}
