#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct r{
	int a,b,c;
	int id;
}a[100001];
r o[100001];
int o_i=0;
bool c1(r x,r y){
	if(x.a-max(x.b,x.c)==y.a-max(y.b,y.c)){
		return x.a>y.a;
	}
	return x.a-max(x.b,x.c)>y.a-max(y.b,y.c);
}
bool c2(r x,r y){
	if(x.b-max(x.a,x.c)==y.b-max(y.a,y.c)){
		return x.b>y.b;
	}
	return x.b-max(x.a,x.c)>y.b-max(y.a,y.c);
}
bool c3(r x,r y){
	if(x.c-max(x.a,x.b)==y.c-max(y.a,y.b)){
		return x.c>y.c;
	}
	return x.c-max(x.a,x.b)>y.c-max(y.a,y.b);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int ___=1;___<=t;___++){
		scanf("%d",&n);
		int x=0,y=0,z=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			if(a[i].a>a[i].b&&a[i].a>a[i].c){
				x++;
			}else if(a[i].b>a[i].a&&a[i].b>a[i].c){
				y++;
			}else{
				z++;
			}
		}
		if(max(x,max(y,z))>n/2){
			if(x>n/2){
				o_i=0;
				for(int i=1;i<=n;i++){
					if(a[i].a>a[i].b&&a[i].a>a[i].c){
						o[++o_i]=a[i];
						o[o_i].id=i;
					}
				}
				sort(o+1,o+o_i+1,c1);
				for(int i=n/2+1;i<=o_i;i++){
					a[o[i].id].a=-1e5;
				}
			}else if(y>n/2){
				o_i=0;
				for(int i=1;i<=n;i++){
					if(a[i].b>a[i].a&&a[i].b>a[i].c){
						o[++o_i]=a[i];
						o[o_i].id=i;
					}
				}
				sort(o+1,o+o_i+1,c2);
				for(int i=n/2+1;i<=o_i;i++){
					a[o[i].id].b=-1e5;
				}
			}else{
				o_i=0;
				for(int i=1;i<=n;i++){
					if(a[i].c>a[i].a&&a[i].c>a[i].b){
						o[++o_i]=a[i];
						o[o_i].id=i;
					}
				}
				sort(o+1,o+o_i+1,c3);
				for(int i=n/2+1;i<=o_i;i++){
					a[o[i].id].c=-1e5;
				}
			}
		}
		long long s=0;
		for(int i=1;i<=n;i++){
			s+=max(a[i].a,max(a[i].b,a[i].c));
		}
		printf("%lld\n",s);
	}
	return 0;
}
