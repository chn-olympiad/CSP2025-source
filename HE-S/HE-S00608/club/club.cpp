#include<bits/stdc++.h>
using namespace std;
struct abc{
	int a,b,c,s,d;
}z[500005];
int t,n,f[4],m,e,g,h;
bool cmp(abc x,abc y){
	if(x.s==y.s){
		if(x.d==y.d){
			if(x.s==1){
				if(x.b==y.b) return x.c>y.c;
				else return x.b>y.b;
			}else if(x.s==2){
				if(x.a==y.a) return x.c>y.c;
				else return x.a>y.a;
			}else{
				if(x.a==y.a) return x.b>y.b;
				else return x.a>y.a;
			}
		}
	}
	return x.s>y.s;
}
int main(){
	freopen("clud.in","r",stdin);
	freopen("clud.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		m=0;
		h=0;
		e=n/2;
		for(int i=0;i<n;i++){
			cin>>z[i].a>>z[i].b>>z[i].c;
			if(z[i].a>=z[i].b){
				z[i].d=z[i].a;
				z[i].s=1;
			}else {
				z[i].s=2;
			    z[i].d=z[i].b;
			}
		    if(z[i].d<=z[i].c){
			 z[i].d=z[i].c;
		       z[i].s=3;
		    }
		}
		sort(z,z+n,cmp);
		for(int i=0;i<n;i++){
			if(z[i].s==1){
				if(f[1]<=e){
					f[1]++;
				    m+=z[i].d;
				}else{
					h=1;
					if(z[i].b>z[i].c){
						m+=z[i].b;
					}else if(z[i].b<z[i].c){
						m+=z[i].c;
					}else{
						int j=max(z[i-1].b,z[i-1].c);
						int k;
						if(z[i-1].b>=z[i-1].c){
							k=2;
						}else k=3;
						if(m-z[i-1].a+j+z[i].a>m+z[i].b){
							m=m-z[i-1].a+j+z[i].a;
							f[k]++;
						}else {
							m+=z[i].b;
							z[i].s=2;
						}
					}
				}
			}else if(z[i].s==2){
				if(f[2]<=e){
					f[2]++;
				    m+=z[i].d;
				}else{
					h=1;
					if(z[i].a>z[i].c){
						m+=z[i].a;
					}else if(z[i].a<z[i].c){
						m+=z[i].c;
					}else{
						int j=max(z[i-1].a,z[i-1].c);
						int k;
						if(z[i-1].a>=z[i-1].c){
							k=1;
						}else k=3;
							g=z[i-1].d;
						if(m-g+j+z[i].b>m+z[i].a){
							m=m-g+j+z[i].b;
							f[k]++;
						}else {
							m+=z[i].c;
						}
					}
				}
			}else {
			if(f[3]<=e){
					f[3]++;
				    m+=z[i].c;
				}else{
					h=1;
					if(z[i].a>z[i].b){
						m+=z[i].a;
					}else if(z[i].a<z[i].b){
						m+=z[i].b;
					}else{
						int j=max(z[i-1].a,z[i-1].b);
						int k;
						if(z[i-1].a>=z[i-1].b){
							k=1;
						}else k=2;
							g=z[i-1].d;
						if(m-g+j+z[i].c>m+z[i].a){
							m=m-g+j+z[i].a;
							f[k]++;
						}else {
							m+=z[i].c;
						}
					}
				}
			}
		}
		if(h==0)
		cout<<m<<endl;
		else
		cout<<m+1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
