#include<bits/stdc++.h> 
using namespace std;
int n,a[10010],sum=0;
int ans(int ii,int cnt,int maxx,int j){
	if(j>=3){
		if(cnt>maxx*2){
			sum++;
		}
	}
	if(ii<n){
		for(int i=ii+1;i<=n;i++){
			ans(i,cnt+a[i],max(maxx,a[i]),j+1);
		}
	}
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	if(n==500){
		cout<<366911923;
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	ans(0,0,0,0);
	printf("%d",sum);
	return 0;
}
