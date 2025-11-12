#include<bits/stdc++.h>
using namespace std;
const int N=100010;
struct pi{
	int a,b,c;
}a[N];
bool cmp1(pi x,pi y){
	return min(x.a-x.b,x.a-x.c)<min(y.a-y.b,y.a-y.c);
}
bool cmp2(pi x,pi y){
	return min(x.b-x.a,x.b-x.c)<min(y.b-y.a,y.b-y.c);
}
bool cmp3(pi x,pi y){
	return min(x.c-x.a,x.c-x.b)<min(y.c-y.a,y.c-y.b);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,ans=0,mx=0,s1=0,s2=0,s3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c)mx+=a[i].a,s1++;
			else if(a[i].b>=a[i].a&&a[i].b>=a[i].c)mx+=a[i].b,s2++;
			else mx+=a[i].c,s3++;
		}
		if(s1<=n/2&&s2<=n/2&&s3<=n/2){
			cout<<mx<<'\n';
			continue;
		}
		mx=0;
		sort(a+1,a+n+1,cmp1);
		ans=0;
		for(int i=1;i<=n;i++){
			if(i<=n/2)ans+=max(a[i].b,a[i].c);
			else ans+=a[i].a;
		}
		mx=max(mx,ans);
		sort(a+1,a+n+1,cmp2);
		ans=0;
		for(int i=1;i<=n;i++){
			if(i<=n/2)ans+=max(a[i].a,a[i].c); 
			else ans+=a[i].b;
		}
		mx=max(mx,ans);
		sort(a+1,a+n+1,cmp3);
		ans=0;
		for(int i=1;i<=n;i++){
			if(i<=n/2)ans+=max(a[i].a,a[i].b); 
			else ans+=a[i].c;
		}
		mx=max(mx,ans);
		cout<<mx<<'\n';
	}
	return 0;
}
