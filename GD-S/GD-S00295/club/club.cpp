#include <bits/stdc++.h>
using namespace std;
long long t,n,m,nx,s,c[3];
struct node{
	long long num,wei;
}a[100010][3],p[5][100010];
bool cmp(node x,node y){
	return x.num>y.num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		c[0]=0;
		c[1]=0;
		c[2]=0;
		nx=1;
		s=0;
		scanf("%lld",&n);
		m=n/2;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][0].num,&a[i][1].num,&a[i][2].num);
			if((a[i][0].num==a[i][1].num)&&(a[i][1].num==a[i][2].num)){
				s+=a[i][0].num;
				continue;
			}
			a[i][0].wei=0;
			a[i][1].wei=1;
			a[i][2].wei=2;
			sort(a[i],a[i]+3,cmp);
			if(a[i][0].num==a[i][1].num){
				s+=a[i][0].num;
				continue;
			}
			s+=a[i][1].num;
			p[t][nx].num=a[i][0].num-a[i][1].num;
			p[t][nx].wei=a[i][0].wei;
			nx+=1;
		}
		sort(p[t]+1,p[t]+nx,cmp);
		for(int i=1;i<nx;i++){
			if(c[p[t][i].wei]<m){
				s+=p[t][i].num;
				c[p[t][i].wei]+=1;
			}
		}
		printf("%lld\n",s);
	}
	return 0;
}
