#include<bits/stdc++.h>
using namespace std;
int n,ans,t;
struct p{
	int b,c,d,cha;
}a[100005];
bool cmp(p x,p y){
	if(x.cha==y.cha&&min(min(max(x.b,x.c),max(x.c,x.d)),max(x.d,x.b ))==min(min(max(y.b,y.c),max(y.c,y.d)),max(y.d,y.b ))) return max(max(x.b,x.c),x.d)>max(max(y.b,y.c),y.d );
	else if(x.cha==y.cha) min(min(max(x.b,x.c),max(x.c,x.d)),max(x.d,x.b )) >min(min(max(y.b,y.c),max(y.c,y.d)),max(y.d,y.b ));
	return x.cha>y.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].b ,&a[i].c ,&a[i].d );
			a[i].cha=max(max(a[i].b ,a[i].c ),a[i].d )-min(min(a[i].b,a[i].c ),a[i].d );
		}
		sort(a+1,a+1+n,cmp);
		int n1=0,n2=0,n3=0;
		for(int i=1;i<=n;i++){
			if(n1*2==n){
				if(a[i].d>a[i].c ){
					ans+=a[i].d;
					n3++;
				}
				else if(a[i].d<a[i].c ){
					ans+=a[i].c;
					n2++;
				}
				else{
					ans+=a[i].c;
				}
			}
			else if(n2*2==n){
				if(a[i].d>a[i].b ){
					ans+=a[i].d;
					n3++;
				}
				else if(a[i].d<a[i].b ){
					ans+=a[i].b ;
					n1++;
				}
				else{
					ans+=a[i].b;
				}
			}
			else if(n3*2==n){
				if(a[i].b>a[i].c ){
					ans+=a[i].b;
					n1++;
				}
				else if(a[i].b<a[i].c ){
					ans+=a[i].c ;
					n2++;
				}
				else{
					ans+=a[i].c;
				}
			}
			else if(a[i].b>a[i].c){
				if(a[i].b>a[i].d ){
					ans+=a[i].b;
					n1++;
				}
				else{
					ans+=a[i].d;
					n3++;
				}
			}
			else{
				if(a[i].c>a[i].d){
					ans+=a[i].c;
					n2++;
				}
				else{
					ans+=a[i].d;
					n3++;
				}
			}
		}
		printf("%d\n",ans);
	}
}
