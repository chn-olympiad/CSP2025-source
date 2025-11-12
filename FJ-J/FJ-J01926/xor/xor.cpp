#include<bits/stdc++.h>
using namespace std;
struct l{
	int ii,jj;
}g[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	ios::_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long long n,k;
	long long a[n+1],t[n+1],p[256]; 
	scanf("%d %d",&n,&k);

	t[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		scanf("%d",a[i]);
		if(i==1) t[1]=a[1];	
		if(i>1) t[i]=t[i-1]+a[i];
	}
	if(n==0){
		printf(0);
		return 0;
	}
	if(n==1){
		if(a[1]==k){
			printf(0);
			return 0;
		}
		else{
			printf(0);
			return 0;
		}
	}
//	ËãÇø¼ä 
	int r=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int f=t[j]-t[i-1];
			if(f==k){
				r++;
//				g[r].ii=i;
//				g[r].jj=j;
			}
		}
	}
//	
//	for(int i=1;i<=r;i++){
//		for(int j=g[i].ii;j<=g[i].jj;j++){
//			p[j]++;
//		}
//	}
//	for(int i=1;i<=256;i++){
//		if(p[i]>=3){
//			int u=p[i]-2;
//			r-=u;
//		}
//	}
	printf("%d\n",r);
	return 0;
} 

