#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int T=1;
int n,m,k,s;
long long ans;
struct Data{
	int a[3],mi,ms,mt;
}a[N];
int b[3];
inline bool cmp(Data x,Data y){
	return x.a[x.mi]-x.a[x.ms]<y.a[y.mi]-y.a[y.ms];
}
void solve(){
//	memset(a,0,sizeof(a));
	ans=0;
	scanf("%d",&n);
//	in(n);
	b[0]=b[1]=b[2]=0;
	for(int i=1;i<=n;++i){
		a[i].mi=0,a[i].ms=1;
		for(int j=0;j<3;++j)scanf("%d",&a[i].a[j]);
//		in(a[i].a[j]);
		if(a[i].a[a[i].ms]>a[i].a[a[i].mi])swap(a[i].mi,a[i].ms);
		if(a[i].a[2]>a[i].a[a[i].ms])a[i].ms=2;
		if(a[i].a[a[i].ms]>a[i].a[a[i].mi])swap(a[i].mi,a[i].ms);
		ans+=a[i].a[a[i].mi];
		++b[a[i].mi]; 
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;++i)
		if(b[a[i].mi]>n/2)b[a[i].mi]--,b[a[i].ms]++,ans-=a[i].a[a[i].mi],ans+=a[i].a[a[i].ms];
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
} 
