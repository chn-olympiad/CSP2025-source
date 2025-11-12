#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,a1,b1,c1,a[N],b[N],c[N],p[N],MAX[N];
struct node1{
	int a,b,c;
}w[N];
struct node2{
	int a,b,c,w;
}u[N];
long long ans;
bool cmp1(node1 x,node1 y){
	int t1=max(x.a,x.b),t2=max(y.a,y.b);
	return t1>t2;
}
bool cmp2(node2 x,node2 y){
	if(x.w==y.w)return max(x.a,max(x.b,x.c))<max(y.a,max(y.b,y.c));
	return x.w<y.w;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;ans=0,a1=0,b1=0,c1=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			MAX[i]=max(a[i],max(b[i],c[i]));
			ans+=MAX[i];b1++;p[i]=2;
			w[i].a=a[i]-b[i];w[i].c=c[i]-b[i];
		}
		sort(w+1,w+1+n,cmp1);
		for(int i=1;i<=n;i++){
			if(w[i].a>w[i].c&&w[i].a>0){
				a1++;b1--;p[i]=1;
			}else if(w[i].a<w[i].c&&w[i].c>0){
				c1++;b1--;p[i]=3;
			}
		}
		for(int i=1;i<=n;i++){
			u[i].a=MAX[i]-a[i];
			u[i].b=MAX[i]-b[i];
			u[i].c=MAX[i]-c[i];
			u[i].w=u[i].a+u[i].b+u[i].c-max(u[i].a,max(u[i].b,u[i].c));
		}
		sort(u+1,u+1+n,cmp2);sort(u+1,u+1+n,cmp2);
		for(int i=1;i<=n;i++){
			cout<<u[i].a<<" "<<u[i].b<<" "<<u[i].c<<endl;
		}
		for(int i=1;i<=n;i++){
			if(p[i]==1){
				if(a1<=n/2)continue;
				a1--;
				if(u[i].b>u[i].c&&c1<n/2){
					ans-=u[i].c;
					c1++;
				}else if(b1<n/2){
					ans-=u[i].b;
					b1++;
				}
			}else if(p[i]==2){
				if(b1<=n/2)continue;
				b1--;
				if(u[i].a>u[i].c&&c1<n/2){
					ans-=u[i].c;
					c1++;
				}else if(a1<n/2){
					ans-=u[i].a;
					a1++;
				}
			}else{
				if(c1<=n/2)continue;
				c1--;
				if(u[i].a>u[i].b&&b1<n/2){
					ans-=u[i].b;
					b1++;
				}else if(a1<n/2){
					ans-=u[i].a;
					a1++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
