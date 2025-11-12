#include<bits/stdc++.h>
namespace kqsscgtk{
	int n,m,N,i,x,a[111];
	void M(){for(scanf("%d%d",&n,&m),N=n*m;i^N;scanf("%d",a+i++));x=*a,std::sort(a,a+N),i=a+N-1-std::lower_bound(a,a+N,x),printf("%d %d",i/n+1,(i/n)&1?n-i%n:i%n+1);}
}
int main(){return freopen("seat.in","r",stdin),freopen("seat.out","w",stdout),kqsscgtk::M(),0;}
