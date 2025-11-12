//club
#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a,b,c;
}e[100007];
bool cmp(node x,node y){
	return x.a-x.b>y.a-y.b;
}
long long f[10007][5007],t,n,A,B,C,ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		scanf("%lld", &n);
		A=B=C=n/2;
		ans=0;
	    for(int i=1; i<=n; i++){
	    	scanf("%lld %lld %lld", &e[i].a,&e[i].b,&e[i].c);
		}
		sort(e+1,e+n+1,cmp);
	    memset(f,0,sizeof(f));
	    f[1][0]=e[1].a;
	    f[1][1]=e[1].c;
		for(int i=2; i<=n; i++){
			for(int x=0; x<=min((long long)i,C); x++){
				long long sum=i-x;
				if(sum<=A) f[i][x]=f[i-1][x]+e[i].a;
				else f[i][x]=f[i-1][x]+e[i].b;
				if(x) f[i][x]=max(f[i][x],f[i-1][x-1]+e[i].c);
			}
		}
		for(int i=0; i<=C; i++){
			ans=max(ans,f[n][i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
