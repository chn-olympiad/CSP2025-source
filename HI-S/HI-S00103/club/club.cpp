#include<bits/stdc++.h>
using namespace std;
struct A{
	int a,b,c;
};
A a[114514];
int T,n;
bool cmp2(A e,A f){
	if(e.c!=f.c){
		return e.c>f.c;
	}else if(e.a!=f.a){
		return e.a<f.a;
	}else{
		return e.b<f.b;
	}
}
bool cmp1(A e,A f){
	if(e.c!=f.c){
		return e.c>f.c;
	}else if(e.b!=f.b){
		return e.b<f.b;
	}else{
		return e.a<f.a;
	}
}
bool cmp3(A e,A f){
	if(e.b!=f.b){
		return e.b>f.b;
	}else if(e.c!=f.c){
		return e.c<f.c;
	}else{
		return e.a<f.a;
	}
}
bool cmp4(A e,A f){
	if(e.b!=f.b){
		return e.b>f.b;
	}else if(e.a!=f.a){
		return e.a<f.a;
	}else{
		return e.c<f.c;
	}
}
bool cmp5(A e,A f){
	if(e.a!=f.a){
		return e.a>f.a;
	}else if(e.b!=f.b){
		return e.b<f.b;
	}else{
		return e.c<f.c;
	}
}
bool cmp6(A e,A f){
	if(e.a!=f.a){
		return e.a>f.a;
	}else if(e.c!=f.c){
		return e.c<f.c;
	}else{
		return e.b<f.b;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int js=0;
	cin>>T;
	while(T--){
		cin>>n;
		js=0;
		int suma=0,sumb=0,sumc=0;
		for(int i=0;i<n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			suma+=a[i].a;sumb+=a[i].b;sumc+=a[i].c;
		}
		if(sumc>=sumb&&sumc>=suma){
			if(sumb>=suma){
				sort(a,a+n,cmp1);
				for(int i=0;i<n/2;i++){
					js+=a[i].c;
				}
				double pj=0;
				for(int i=n/2;i<n;i++){
					pj+=a[i].b;pj+=a[i].c;
				}
				pj/=(1.0*n/2);
				for(int i=n/2;i<n;i++){
					if(a[i].a>pj){
						js+=a[i].a;
					}else{
						js+=a[i].b;
					}
				}
			}else{
				sort(a,a+n,cmp2);
				for(int i=0;i<n/2;i++){
					js+=a[i].c;
				}
				double pj=0;
				for(int i=n/2;i<n;i++){
					pj+=a[i].b;pj+=a[i].c;
				}
				pj/=(1.0*n/2);
				for(int i=n/2;i<n;i++){
					if(a[i].a>pj){
						js+=a[i].a;
					}else{
						js+=a[i].b;
					}
				}
			}
		}else if(sumb>=sumc&&sumb>=suma){
			if(sumc>=suma){
				sort(a,a+n,cmp3);
				for(int i=0;i<n/2;i++){
					js+=a[i].b;
				}
				double pj=0;
				for(int i=n/2;i<n;i++){
					pj+=a[i].a;pj+=a[i].c;
				}
				pj/=(1.0*n/2);
				for(int i=n/2;i<n;i++){
					if(a[i].a>pj){
						js+=a[i].a;
					}else{
						js+=a[i].c;
					}
				}
			}else{
				sort(a,a+n,cmp4);
				for(int i=0;i<n/2;i++){
					js+=a[i].b;
				}
				double pj=0;
				for(int i=n/2;i<n;i++){
					pj+=a[i].a;pj+=a[i].c;
				}
				pj/=(1.0*n/2);
				for(int i=n/2;i<n;i++){
					if(a[i].a>pj){
						js+=a[i].a;
					}else{
						js+=a[i].c;
					}
				}
			}
		}else{
			if(sumb>=sumc){
				sort(a,a+n,cmp5);
				for(int i=0;i<n/2;i++){
					js+=a[i].a;
				}
				double pj=0;
				for(int i=n/2;i<n;i++){
					pj+=a[i].b;pj+=a[i].c;
				}
				pj/=(1.0*n/2);
				for(int i=n/2;i<n;i++){
					if(a[i].b>pj){
						js+=a[i].b;
					}else{
						js+=a[i].c;
					}
				}
			}else{
				sort(a,a+n,cmp6);
				for(int i=0;i<n/2;i++){
					js+=a[i].a;
				}
				double pj=0;
				for(int i=n/2;i<n;i++){
					pj+=a[i].b;pj+=a[i].c;
				}
				pj/=(1.0*n/2);
				for(int i=n/2;i<n;i++){
					if(a[i].b>pj){
						js+=a[i].b;
					}else{
						js+=a[i].c;
					}
				}
			}
		}
		cout<<js<<endl;
	}
	return 0;
}

