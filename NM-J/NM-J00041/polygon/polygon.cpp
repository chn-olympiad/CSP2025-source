#include<bits/stdc++.h>
using namespace std;
int a[5005],n,cnt,b[5005];
int cntt(int x){
	if(x==n) {
		return 1;
	}
	else if(b[x]!=0){
		return b[x];
	}
	else{
		return b[x]=1+cntt(x-1);
	}
}
bool cmp(int c,int d){
	return c>d;
}
bool deal(int x,int y){
	int sum=0,maxx=0;
	for(int i=x+1;i<=y;++i){
		sum+=a[i];
		maxx=max(a[i],a[i-1]);
	}
	if(maxx*2<sum){
		return true;
	}
	return false;
}
int main(){
	freopen("polgon.in","r",stdin);
	freopen("polgon.out","w",stdout);
	scanf("%d",&n);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	printf("%d",cntt(n));
}
