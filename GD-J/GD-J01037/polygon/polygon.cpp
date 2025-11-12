#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5005],ans=0,flag=true;
int pai(int n){
	if(n==0) return 0;
	if(n==1) return 1;
	else return 2*pai(n-1)+1;
}
void f(int maxn,int minn,int he){
	//	printf("%d,%d,%d,%d\n",maxn,minn,he,ans);
	if((a[maxn]*2)<(he+a[minn])){
			//printf("%d,%d,%d,%d\n",maxn,minn,he,ans);
		ans=ans+1+pai(minn-1);
	}
	else{
		for(int i=1;i<minn;i++){
			f(maxn,i,he+a[minn]);
		}
	}
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=1) flag=false;
	}
	if(flag){
		printf("%lld",pai(n)-4);
		return 0;
	}
	sort(a+1,a+1+n); 
	for(int i=3;i<=n;i++){
		f(i,i,0);
	}
	printf("%lld",ans);
	return 0;
}
