#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXX=998244353;
int n,a[5005];
//好吧或许我不应该觉得我t4可以做出来的 
//void f(int sum,int x){
//	for(int i=1;i<=sum;i++){
//		f(sum-1,)
//	}
//}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<3) cout<<0;
	if(n==3){
		if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2)
			cout<<1;
		else cout<<0;
	}
	if(n==4){
		int t=0,maxx=-INT_MAX;
		for(int i=1;i<=4;i++) {
			t+=a[i];
			maxx=(maxx,a[i]);
		}
		if(t>2*maxx) cout<<1;
		
	}
//	for(int i=3;i<=n;i++){//最多n边形 
//		f(i,1);
//	} 
	return 0; 
} 
