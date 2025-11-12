#include<bits/stdc++.h>
using namespace std;
long long n,q,c[200010],d[200010],e,f,t,g,h;
char a[5000010],b[5000010],x[5000010],y[5000010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(long long o=0;o<n;o++){
		scanf("%s%s",a,b);
		g=strlen(a);
		for(long long i=0;i<g;i++){
			if(a[i]=='b') c[o]=i;
			if(b[i]=='b') d[o]=i;
		}
	}
	for(long long o=0;o<q;o++){
		scanf("%s%s",x,y);
		h=strlen(x);
		for(long long i=0;i<h;i++){
			if(x[i]=='b') e=i;
			if(y[i]=='b') f=i;
		}
		if(f>e) for(long long o=0;o<n;o++) if(d[o]-c[o]==f-e) t++;
		else for(long long o=0;o<n;o++) if(c[o]-d[o]==e-f) t++;
		printf("%lld\n",t);
	}
	return 0;
} 
