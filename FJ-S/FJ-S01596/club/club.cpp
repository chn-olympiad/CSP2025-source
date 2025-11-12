#include<bits/stdc++.h>
namespace umrofcen{
	int t,n,m,i,A,B,C,s,a[100100],b[100100],c[100100],w[100100],x[100100],y[100100],z[100100];
	void M(){
		for(scanf("%d",&t);t--;printf("%d\n",s)){
			for(A=B=C=i=s=0,scanf("%d",&n),m=n>>1;i++^n;){
				scanf("%d%d%d",a+i,b+i,c+i);
				if(a[i]>=b[i]&&a[i]>=c[i])x[A++]=i,s+=a[i];
				else if(b[i]>=a[i]&&b[i]>=c[i])y[B++]=i,s+=b[i];
				else z[C++]=i,s+=c[i];
			}
			if(A>m){for(i=0;i^A;++i)w[i]=a[x[i]]-std::max(b[x[i]],c[x[i]]);for(std::sort(w,w+A),i=A-m;i;s-=w[--i]);}
			else if(B>m){for(i=0;i^B;++i)w[i]=b[y[i]]-std::max(a[y[i]],c[y[i]]);for(std::sort(w,w+B),i=B-m;i;s-=w[--i]);}
			else if(C>m){for(i=0;i^C;++i)w[i]=c[z[i]]-std::max(a[z[i]],b[z[i]]);for(std::sort(w,w+C),i=C-m;i;s-=w[--i]);}
		}
	}
};
int main(){return freopen("club.in","r",stdin),freopen("club.out","w",stdout),umrofcen::M(),0;}
