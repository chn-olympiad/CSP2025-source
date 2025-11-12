#include "iostream"
#include "algorithm"
#include "cstring"
#include "cmath"
using namespace std;
long long s=0;
int t,n,a1=0,b1=0,c1=0;//lena=1,lenb=1,lenc=1
struct node {
	int a,b,c,f=1,id;
}a[100005],da[100005],db[100005],dc[100005];
bool cmpa(node q,node w){
	return q.a<w.a;
}
bool cmpb(node q,node w){
	return q.b<w.b;
}
bool cmpc(node q,node w){
	return q.c<w.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	memset(a,0,sizeof(a));
	memset(da,0,sizeof(da));
	memset(db,0,sizeof(db));
	memset(dc,0,sizeof(dc));
	while(t--){
		s=0;
		a1=0,b1=0,c1=0;
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d %d %d",&a[i].a,&a[i].b,&a[i].c);
			a[i].id=i,a[i].f=1;
		}
		sort(a+1,a+n+1,cmpa);
		for(int i=1;i<=n;++i){
			if(max(max(a[i].a,a[i].b),a[i].c)==a[i].a&&a1<n/2)
				s+=a[i].a,a[i].f=0,++a1;
		}
		sort(a+1,a+n+1,cmpb);
		for(int i=1;i<=n;++i){
			if(max(max(a[i].a,a[i].b),a[i].c)==a[i].b&&a[i].f==1&&b1<n/2)
				s+=a[i].b,a[i].f=0,++b1;
		}
		sort(a+1,a+n+1,cmpc);
		for(int i=1;i<=n;++i){
			if(max(max(a[i].a,a[i].b),a[i].c)==a[i].c&&a[i].f==1&&c1<n/2)
				s+=a[i].c,a[i].f=0,++c1;
		}
		cout<<s<<'\n';
	}
}
