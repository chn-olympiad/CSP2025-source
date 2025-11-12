#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long n;
long long a[N],b[N],c[N];
long long s(long long q1,long long q2){
	return max(a[q1]+max(b[q2],c[q2]),max(b[q1]+max(c[q2],a[q2]),c[q1]+max(a[q2],b[q2])));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		for(long long i=0;i<n;i++){
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		}
		if(n==2){
			printf("%lld\n",s(1,0));
			continue;
		}
		long long s1=0,f=0;
	for(long long i=0;i<n;i++){
		for(long long j=i+1;j<n-i;j++){
			f=max(f,s(i,j));
		}
		s1+=f;
		f=0;
	}
	printf("%lld\n",s1);
	}
	return 0;
}
