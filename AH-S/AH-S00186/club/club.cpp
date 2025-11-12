#include<bits/stdc++.h>
using namespace std;
struct num{long long a,b,c,p1,p2,p3;}a[int(1e5)+10];
bool cmp1(const num &x,const num &y){
	return x.a>y.a;
}
bool cmp2(const num &x,const num &y){
	return x.b>y.b;
}
bool cmp3(const num &x,const num &y){
	return x.c>y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		long long n,an=0,bn=0,cn=0,k=0,maxn=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			 cin>>a[i].a>>a[i].b>>a[i].c;
			 long long o1=max(a[i].a,max(a[i].b,a[i].c)),o3=min(a[i].a,min(a[i].b,a[i].c));
			 if((a[i].a!=o1&&a[i].a!=o3)) a[i].p2=1;
			 if((a[i].b!=o1&&a[i].b!=o3)) a[i].p2=2;
			 if((a[i].c!=o1&&a[i].c!=o3)) a[i].p2=3;
			 if(o1==a[i].a) a[i].p1=1;
			 if(o3==a[i].a) a[i].p3=1;
			 if(o1==a[i].b) a[i].p1=2;
			 if(o3==a[i].b) a[i].p3=2;
			 if(o1==a[i].c) a[i].p1=3;
			 if(o3==a[i].c) a[i].p3=3;
		 }
		 for(int i=1;i<=n;i++){
			 if(a[i].p1==1){
				 if(an+1<=n/2){an++;k+=a[i].a;}
				 else{
					if(a[i].p2==2){
						if(bn+1<=n/2){bn++;k+=a[i].b;}
						else {cn++;k+=a[i].c;}
					}
					if(a[i].p2==3){
						if(cn+1<=n/2){cn++;k+=a[i].c;}
						else {bn++;k+=a[i].b;}
					}
				 }
			 }
			 if(a[i].p1==2){
				 if(bn+1<=n/2){bn++;k+=a[i].b;}
				 else{
					if(a[i].p2==1){
						if(an+1<=n/2){an++;k+=a[i].a;}
						else {cn++;k+=a[i].c;}
					}
					if(a[i].p2==3){
						if(cn+1<=n/2){cn++;k+=a[i].c;}
						else {an++;k+=a[i].a;}
					}
				 }
			 }
			 if(a[i].p1==3){
				 if(cn+1<=n/2){cn++;k+=a[i].c;}
				 else{
					if(a[i].p2==2){
						if(bn+1<=n/2){bn++;k+=a[i].b;}
						else {cn++;k+=a[i].c;}
					}
					if(a[i].p2==1){
						if(an+1<=n/2){an++;k+=a[i].a;}
						else {bn++;k+=a[i].b;}
					}
				 }
			 }
		 }
		maxn=max(maxn,k);an=0,bn=0,cn=0,k=0;
		 sort(a+1,a+n+1,cmp1);
		 for(int i=1;i<=n;i++){
			 if(a[i].p1==1){
				 if(an+1<=n/2){an++;k+=a[i].a;}
				 else{
					if(a[i].p2==2){
						if(bn+1<=n/2){bn++;k+=a[i].b;}
						else {cn++;k+=a[i].c;}
					}
					if(a[i].p2==3){
						if(cn+1<=n/2){cn++;k+=a[i].c;}
						else {bn++;k+=a[i].b;}
					}
				 }
			 }
			 if(a[i].p1==2){
				 if(bn+1<=n/2){bn++;k+=a[i].b;}
				 else{
					if(a[i].p2==1){
						if(an+1<=n/2){an++;k+=a[i].a;}
						else {cn++;k+=a[i].c;}
					}
					if(a[i].p2==3){
						if(cn+1<=n/2){cn++;k+=a[i].c;}
						else {an++;k+=a[i].a;}
					}
				 }
			 }
			 if(a[i].p1==3){
				 if(cn+1<=n/2){cn++;k+=a[i].c;}
				 else{
					if(a[i].p2==2){
						if(bn+1<=n/2){bn++;k+=a[i].b;}
						else {cn++;k+=a[i].c;}
					}
					if(a[i].p2==1){
						if(an+1<=n/2){an++;k+=a[i].a;}
						else {bn++;k+=a[i].b;}
					}
				 }
			 }
		 }
		maxn=max(maxn,k);an=0,bn=0,cn=0,k=0;
		 sort(a+1,a+n+1,cmp2);
		 for(int i=1;i<=n;i++){
			 if(a[i].p1==1){
				 if(an+1<=n/2){an++;k+=a[i].a;}
				 else{
					if(a[i].p2==2){
						if(bn+1<=n/2){bn++;k+=a[i].b;}
						else {cn++;k+=a[i].c;}
					}
					if(a[i].p2==3){
						if(cn+1<=n/2){cn++;k+=a[i].c;}
						else {bn++;k+=a[i].b;}
					}
				 }
			 }
			 if(a[i].p1==2){
				 if(bn+1<=n/2){bn++;k+=a[i].b;}
				 else{
					if(a[i].p2==1){
						if(an+1<=n/2){an++;k+=a[i].a;}
						else {cn++;k+=a[i].c;}
					}
					if(a[i].p2==3){
						if(cn+1<=n/2){cn++;k+=a[i].c;}
						else {an++;k+=a[i].a;}
					}
				 }
			 }
			 if(a[i].p1==3){
				 if(cn+1<=n/2){cn++;k+=a[i].c;}
				 else{
					if(a[i].p2==2){
						if(bn+1<=n/2){bn++;k+=a[i].b;}
						else {cn++;k+=a[i].c;}
					}
					if(a[i].p2==1){
						if(an+1<=n/2){an++;k+=a[i].a;}
						else {bn++;k+=a[i].b;}
					}
				 }
			 }
		 }
		 maxn=max(maxn,k);an=0,bn=0,cn=0,k=0;
		 sort(a+1,a+n+1,cmp3);
		 for(int i=1;i<=n;i++){
			 if(a[i].p1==1){
				 if(an+1<=n/2){an++;k+=a[i].a;}
				 else{
					if(a[i].p2==2){
						if(bn+1<=n/2){bn++;k+=a[i].b;}
						else {cn++;k+=a[i].c;}
					}
					if(a[i].p2==3){
						if(cn+1<=n/2){cn++;k+=a[i].c;}
						else {bn++;k+=a[i].b;}
					}
				 }
			 }
			 if(a[i].p1==2){
				 if(bn+1<=n/2){bn++;k+=a[i].b;}
				 else{
					if(a[i].p2==1){
						if(an+1<=n/2){an++;k+=a[i].a;}
						else {cn++;k+=a[i].c;}
					}
					if(a[i].p2==3){
						if(cn+1<=n/2){cn++;k+=a[i].c;}
						else {an++;k+=a[i].a;}
					}
				 }
			 }
			 if(a[i].p1==3){
				 if(cn+1<=n/2){cn++;k+=a[i].c;}
				 else{
					if(a[i].p2==2){
						if(bn+1<=n/2){bn++;k+=a[i].b;}
						else {cn++;k+=a[i].c;}
					}
					if(a[i].p2==1){
						if(an+1<=n/2){an++;k+=a[i].a;}
						else {bn++;k+=a[i].b;}
					}
				 }
			 }
		 }
		 maxn=max(maxn,k);
		 cout<<k<<'\n';
	}
	return 0;
}
