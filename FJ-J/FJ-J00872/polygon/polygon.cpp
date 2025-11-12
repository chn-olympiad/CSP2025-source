#include <bits/stdc++.h>
using namespace std;
int a[5020],n,v,x,y;
long long m;
bool cmp(int b,int c){
	return b<c;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
	    scanf("%d",&a[i]);
    }
    
	sort(a+1,a+n+1,cmp);
	if(n<=3){
    	if(a[3]*2<a[1]+a[2]+a[3]&&n==3)printf("1");
    	if(n<=2||a[3]*2>=a[1]+a[2]+a[3])printf("0");
    }
	for(int i=1;i<n-1;i++){
	    for(int j=i+2;j<=n;j++){
	    	x=0;
			for(int c=i;c<=j;c++)x+=a[c];
	    	if(x>a[j]*2&&j-i+1>=3)m++;
		}
    }  
	printf("%lld",m%998244353);
    return 0;
}  
