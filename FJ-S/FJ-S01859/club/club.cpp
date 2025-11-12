#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;

struct Club{
	long long a,b,c;
} e[N];

bool cmp1(Club x,Club y){
	return x.b>y.b;
}

bool cmp2(Club x,Club y){
	return x.c>y.c;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;scanf("%d",&t);
	while (t--){
		int n;scanf("%d",&n);
		long long sum=0;
		for (int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&e[i].a,&e[i].b,&e[i].c);
			sum+=e[i].a;
			e[i].b-=e[i].a;
			e[i].c-=e[i].a;
		}
		
		sort(e+1,e+1+n,cmp1);
		for (int i=1;i<=n/2;i++){
			sum+=e[i].b;
			e[i].c-=e[i].b;
		}
		sort(e+1,e+1+n,cmp2);
		
		for (int i=1;i<=n/2&&e[i].c>0;i++){
			sum+=e[i].c;
		}
		
		printf("%lld\n",sum);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
