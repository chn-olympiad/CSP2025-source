#include<bits/stdc++.h>
using namespace std;int a,b[5001],i,c[5001]={1},j,l,t,u;long long p=998244353;
main(){
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	scanf("%d",&a);for(i=1;i<=a;i++)scanf("%d",&b[i]);sort(b+1,b+1+a);
	for(i=u=1;i<=a;i++,u=u*2%p){
		(t+=u)%p;for(j=0;j<=b[i];j++)t=(t-c[j]+p)%p;
		for(j=10000;j>=b[i];j--)(c[j]+=c[j-b[i]])%=p;
	}printf("%d",t);
}
