#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n;
struct node{
	ll b,c,d;
}a[100010];
bool cmp1(node x,node y){
	return x.b<y.b;
}
bool cmp2(node x,node y){
	return x.c-x.b>y.c-y.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		ll t1=0,t2=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].b,&a[i].c,&a[i].d);
			if(a[i].b&&!a[i].c&&!a[i].d)t1++;
			else if(a[i].b&&a[i].c&&!a[i].d)t2++;
		}
		if(t1==n){
			ll s=0;
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n/2;i++)
			s+=a[i].b;
			printf("%lld\n",s);
			continue;
		}
		if(t2==n){
			ll s=0;
			for(int i=1;i<=n;i++)
			s+=a[i].b;
			sort(a+1,a+1+n,cmp2);
			for(int i=1;i<=n/2;i++)
			s+=a[i].c-a[i].b;
			printf("%lld\n",s);
			continue;
		}
		ll s=0;
		for(int i=1;i<=n;i++)
		s+=max({a[i].b,a[i].c,a[i].d});
		printf("%lld\n",s);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
