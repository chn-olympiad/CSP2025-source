#include <bits/stdc++.h>
using namespace std;
int T;
int n,sum;
struct edge{
	int a,b,c;
}a[100005];
bool cmp(edge x,edge y){
	int X=max(x.a,max(x.b,x.c))+min(x.a,min(x.b,x.c))+max(x.a,max(x.b,x.c))-x.b-x.a-x.c;
	
	int Y=max(y.a,max(y.b,y.c))+min(y.a,min(y.b,y.c))+max(y.a,max(y.b,y.c))-y.b-y.a-y.c;
	
	return X>Y;
}

int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		sum=0;
		int suma=0,sumb=0,sumc=0;
		scanf("%d",&n);
		int m=n/2;
		for(int i=1;i<=n;i++)	scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
				if(suma<m){
					sum+=a[i].a;
					suma++;
					continue;
				}
				if(a[i].b>=a[i].c){
					if(sumb<m){
						sum+=a[i].b;
						sumb++;
					}else{
						sum+=a[i].c;
						sumc++;
					}
					continue;
				}
				if(a[i].c>=a[i].b){
					if(sumc<m){
						sum+=a[i].c;
						sumc++;
					}else{
						sum+=a[i].b;
						sumb++;
					}
				}
			}else if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
				if(sumb<m){
					sum+=a[i].b;
					sumb++;
					continue;
				}
				if(a[i].a>=a[i].c){
					if(suma<m){
						sum+=a[i].a;
						suma++;
					}else{
						sum+=a[i].c;
						sumc++;
					}
					continue;
				}
				if(a[i].c>=a[i].a){
					if(sumc<m){
						sum+=a[i].c;
						sumc++;
					}else{
						sum+=a[i].a;
						suma++;
					}
				}
			}else if(a[i].c>=a[i].b&&a[i].c>=a[i].a){
				if(sumc<m){
					sum+=a[i].c;
					sumc++;
					continue;
				}
				if(a[i].b>=a[i].a){
					if(sumb<m){
						sum+=a[i].b;
						sumb++;
					}else{
						sum+=a[i].a;
						suma++;
					}
					continue;
				}
				if(a[i].a>=a[i].b){
					if(suma<m){
						sum+=a[i].a;
						suma++;
					}else{
						sum+=a[i].b;
						sumb++;
					}
				}
			}
		}
		cout << sum << '\n';
	}
	return 0;
}
