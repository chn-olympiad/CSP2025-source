#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[10001][10001];
struct{
	long long u;
	long long v;
	long long w;
	long long c;
	bool ll; 
}b[100001];
int main(){
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout); 
	long long m,k; 
	scanf("%lld,%lld,%lld",&n,&m,&k); 
	
	for(int i=1;i<=m;i++){ 
		scanf("%lld,%lld,%lld",&b[i].u,&b[i].v,&b[i].w); 
	} 
	for(int i=1;i<=k;i++){
		scanf("%lld",&b[i].c);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]); 
		}
	}
	long long z=0Xff,c=0,q=0Xff,small[100001];
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			small[j]=0Xff;
			small[j]=min(small[j],min(a[i][j],b[i].w));
			if(b[i].ll==0&&small[j]==a[i][j]){
				b[i].ll=1;
				c+=b[i].c;
			}
			c+=small[j];
		}
		if(i>=2){
			q=min(q,c);
		}
	}
	printf("%lld",&q);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
