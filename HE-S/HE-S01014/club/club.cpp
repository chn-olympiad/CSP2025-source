#include<bits/stdc++.h>
using namespace std;
int t,n,ji[4],n2;
struct student{
	int t1,t2;
	long long b1,b2;
}a[100005];
long long sum;
struct manyi{
	int num,s;
}m[3];
bool cmp(manyi x,manyi y){
	return x.s>y.s;
}
bool cmp1(student x1,student x2){
	return (x1.t1-x1.t2)>(x2.t1-x2.t2);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);n2=n>>1;sum=0;
		memset(ji,0,sizeof(ji));
		for(int i=1;i<=n;i++){
			scanf("%lld %lld %lld",&m[0].s,&m[1].s,&m[2].s);
			m[0].num=1;m[1].num=2;m[2].num=3;
			sort(m,m+3,cmp);
			a[i].t1=m[0].s;a[i].t2=m[1].s;
			a[i].b1=m[0].num;a[i].b2=m[0].num;
		}
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++){
			if(ji[a[i].b1]<n2){
				sum+=a[i].t1;ji[a[i].b1]++;
			}
			else{
				sum+=a[i].t2;ji[a[i].b2]++;
			}
		}
		printf("%lld\n",sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
