#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N],b[N],c[N];
bool cmp(int q,int w){
	return q>w;
}
void sol1(){
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+n,cmp);
	long long ans=0;
	for(int i=1;i<=n/2;i++) ans+=a[i]+b[i];
	cout<<ans<<"\n";
}
void sol2(){
	cout<<max({a[1]+b[2],a[1]+c[2],b[1]+a[2],b[1]+c[2],c[1]+a[2],c[1]+b[2]})<<"\n";
}
void sol3(){
	int ans=0;
	for(int i=1;i<=n;i++) ans+=max({a[i],b[i],c[i]});
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		bool f=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			if(c[i]!=0) f=0;
		} 
		if(f) sol1();
		else if(n==2) sol2();
		else sol3();
	}
	return 0;
}
