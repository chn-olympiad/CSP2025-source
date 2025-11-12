#include<bits/stdc++.h>
using namespace std;
long long q,n,a[100005][4],cnt,sum,b[100005],cs[4];
struct node{
	long long t,k,l;
}s[300005];
bool cmp(node x,node y){
	return x.t>y.t;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&q);
	while(q--){
		scanf("%lld",&n);
		cnt=0;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
				s[++cnt].t=a[i][j];
				s[cnt].k=i;
				if(j==1) s[cnt].l=1;
				else if(j==2) s[cnt].l=2;
				else s[cnt].l=3;
			}
		}
		sort(s+1,s+1+3*n,cmp);
		sum=0;
		memset(b,0,sizeof(b));
		memset(cs,0,sizeof(cs));
		for(long long i=1;i<=3*n;i++){
			if(b[s[i].k]==0&&cs[s[i].l]<n/2){
				sum+=s[i].t;
				b[s[i].k]++;
				cs[s[i].l]++;
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
} 
