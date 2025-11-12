#include<bits/stdc++.h>
namespace kqsscgtk{
	using L=long long;
	const int p=998244353;
	int n,i,j,s=1,t=2,v,x,a[5050],f[5050];
	void A(int&x,int y){x+=x+y<p?y:y-p;}
	void B(int&x,int y){x-=x<y?y-p:y;}
	void M(){
		for(scanf("%d",&n);i^n;v<x?v=x:0,a[++i]=x)scanf("%d",&x);
		for(;i;i>>=1,t=L(t)*t%p)i&1?s=L(s)*t%p:0;
		for(i=v;~i;f[i--]=1);
		for(i=0,B(s,1),std::sort(a+1,a+n+1);i^n;)for(j=v,B(s,f[x=a[++i]]);j>=x;--j)A(f[j],f[j-x]);printf("%d",s);
	}
}
int main(){return freopen("polygon.in","r",stdin),freopen("polygon.out","w",stdout),kqsscgtk::M(),0;}
