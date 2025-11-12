#include<bits/stdc++.h>
using namespace std;
struct xx{
	int a,b,c;
}a[100005];
bool cmp(xx x,xx y){
	return x.c>y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			a[i].c=a[i].a-a[i].b;
		}
		long long s=0;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			s+=1LL*a[i].a;
		} 
		for(int i=n/2+1;i<=n;i++){
			s+=1LL*a[i].b;
		}
		printf("%lld\n",s);
	}
}
