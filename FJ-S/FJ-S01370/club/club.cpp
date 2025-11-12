#include<bits/stdc++.h>
using namespace std;
int o,n,f,a[10];
long long a_1,a_2,a_3;

struct gg{
	int a,b,c,maxa,maxb,maxc,ch;
}e[1000005];

bool cmp(gg x,gg y){
	if(x.a!=y.a){
		return x.a>y.a;
	}else if(x.b!=y.b){
		return x.b<y.b;
	}
	return x.c<y.c;
}

bool cmp_2(gg x,gg y){
	if(x.b!=y.b){
		return x.b>y.b;
	}
	if(x.c!=y.c){
		return x.c<y.c;
	}
	return x.a<y.a;
}

bool cmp_3(gg x,gg y){
	if(x.c!=y.c){
		return x.c>y.c;
	}
	if(x.a!=y.a){
		return x.a<y.a;
	}
	return x.b<y.b;
}


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>o;
	while(o--){
		cin>>n;
		f=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c);
			e[i].ch=0;
			e[i].maxa=0;
			e[i].maxb=0;
			e[i].maxc=0;
			if(e[i].a>=e[i].b&&e[i].a>=e[i].c){
				e[i].maxa=1;
				if(e[i].b>=e[i].c){
					e[i].maxb=2;
					e[i].maxc=3;
				}else{
					e[i].maxb=3;
					e[i].maxc=2;
				}
			}else if(e[i].b>=e[i].c){
				e[i].maxa=2;
				if(e[i].a>=e[i].c){
					e[i].maxb=1;
					e[i].maxc=3;
				}else{
					e[i].maxb=3;
					e[i].maxc=1;
				}
			}else{
				e[i].maxa=3;
				if(e[i].a>=e[i].b){
					e[i].maxb=1;
					e[i].maxc=2;
				}else{
					e[i].maxb=2;
					e[i].maxc=1;
				}
			}
		}
		sort(e+1,e+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(e[i].maxa==1){
				e[i].ch=1;
				a[1]++;
				a_1=a_1+e[i].a;
				if(a[1]>=f){
					break;
				}
			}
		}
		sort(e+1,e+n+1,cmp_2);
		for(int i=1;i<=n;i++){
			if(e[i].maxa==2){
				e[i].ch=2;
				a[2]++;
				a_2=a_2+e[i].b;
				if(a[2]>=f){
					break;
				}
			}
		}
		sort(e+1,e+n+1,cmp_3);
		for(int i=1;i<=n;i++){
			if(e[i].maxa==3){
				e[i].ch=3;
				a[3]++;
				a_3=a_3+e[i].c;
				if(a[3]>=f){
					break;
				}
			}
		}
		if(a[1]+a[2]+a[3]<n){
			sort(e+1,e+n+1,cmp);
			for(int i=1;i<=n&&a[1]<f;i++){
				if(e[i].maxb==1&&e[i].ch==0){
					e[i].ch=1;
					a[1]++;
					a_1=a_1+e[i].a;
					if(a[1]>=f){
						break;
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]<n){
			sort(e+1,e+n+1,cmp_2);
			for(int i=1;i<=n&&a[2]<f;i++){
				if(e[i].maxb==2&&e[i].ch==0){
					e[i].ch=2;
					a[2]++;
					a_2=a_2+e[i].b;
					if(a[2]>=f){
						break;
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]<n){
			sort(e+1,e+n+1,cmp_3);
			for(int i=1;i<=n&&a[3]<f;i++){
				if(e[i].maxb==3&&e[i].ch==0){
					e[i].ch=3;
					a[3]++;
					a_3=a_3+e[i].c;
					if(a[3]>=f){
						break;
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]<n){
			for(int i=1;i<=n&&a[1]<f;i++){
				if(e[i].maxc==1&&e[i].ch==0&&a[1]<f){
					e[i].ch=1;
					a[1]++;
					a_1=a_1+e[i].a;
				}else if(e[i].maxc==2&&e[i].ch==0&&a[2]<f){
					e[i].ch=2;
					a[2]++;
					a_2=a_2+e[i].b;
				}else if(e[i].maxc==3&&e[i].ch==0&&a[3]<f){
					e[i].ch=3;
					a[3]++;
					a_3=a_3+e[i].c;
				}
			}
		}
		cout<<a_1+a_2+a_3<<endl;
		a_1=0;
		a_2=0;
		a_3=0;
		a[1]=0;
		a[2]=0;
		a[3]=0;
		f=0;
	}
	return 0;
} 
