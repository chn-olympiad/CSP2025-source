#include<bits/stdc++.h>
using namespace std;
struct U{int x , y ;}ans[500005];
long long n , k , cnt , a[500005] , sum[500005] ;
bool flagA=1 , flagB=1 , flagC=1 ;
bool cmp(U x1 , U x2){
	if(x1.x<x2.x)return 1;
	else if(x1.x==x2.x)
		if(x1.y<x2.y)return 1;
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]^a[i];
		if(a[i]!=1)flagA=0;
		if(a[i]>1)flagB=0;
		if(a[i]>255)flagC=0;
	}
	sort(a+1,a+1+n);
	if(k==0){
		if(flagA)printf("%lld",n/2);
		return 0;
	}
	if(flagB){
		long long res=0 ;
		for(int i=1;i<=n;i++)res+=a[i];
		printf("%lld",res);
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if((sum[i]^sum[j-1])==k)
				ans[++cnt].x=j,ans[cnt].y=i;
		}
	}
	// cout << "\n" ;
	sort(ans+1,ans+1+cnt,cmp);
	// for(int i=1;i<=cnt;i++)cout << ans[i].x << " " << ans[i].y << "\n" ;
	long long resans=0 ;
	for(int j=1;j<=cnt;j++){
		long long res=1 , last=j ;
		for(int i=j+1;i<=cnt;i++){
			if(ans[i].x<=ans[last].y)continue;
			res++;
			last=i;
		}
		resans=max(resans,res);
	}
	printf("%lld",resans);
	return 0;
}
//MJWYYDS
//csp rp++
//保佑我csp-j上300
//苗晋玮保佑我csp-j上300