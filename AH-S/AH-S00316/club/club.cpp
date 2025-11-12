#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int d[3];
	int p;
}a[100005];
int b[4];
bool cmp(node x,node y){
	return x.d>y.d;
}
long long ans;
void init(){
	scanf("%d",&n);
	b[1]=b[2]=b[0]=0;
	ans=0;
	int mx;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].d[0],&a[i].d[1],&a[i].d[2]);
		mx=0;
		for(int j=1;j<3;j++){
			if(a[i].d[j]>a[i].d[mx])mx=j;
		}
		a[i].p=mx;
		ans+=a[i].d[mx];
		b[mx]++;
	}
	return;
}
int c[100005],m;
void work(){
	m=0;
	int p=-1;
	if(b[1]*2>n)p=1;
	if(b[2]*2>n)p=2;
	if(b[0]*2>n)p=0;
	if(p==-1){
		printf("%lld\n",ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(a[i].p==p){
			c[++m]=min(a[i].d[p]-a[i].d[(p+1)%3],a[i].d[p]-a[i].d[(p+2)%3]);
		}
	}
	sort(c+1,c+1+m);
	for(int i=1;i<=b[p]-n/2;i++){
		ans-=c[i];
		//~ cout<<c[i]<<endl;
	}
	printf("%lld\n",ans);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	//~ t=1;
	while(t--){
		init();
		work();
	}
	return 0;
}
