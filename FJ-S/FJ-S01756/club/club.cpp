#include<bits/stdc++.h>
using namespace std;
long long n,t,d,e,f,m,s,l=1e9,g;
struct xy{
	long long a,b,c;
	long long f,s,t;
	long long o,w,h;
	long long x,y,z;
}r[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		m=n/2;
		l=1e9;
		d=e=f=s=0;
		for(int i=1;i<=n;++i){
			cin>>r[i].a>>r[i].b>>r[i].c;
			if(r[i].a>=r[i].b){
				if(r[i].a>=r[i].c){
					r[i].f=r[i].a;
					r[i].o=1;
					++d;
				}else{
					r[i].f=r[i].c;
					r[i].o=3;
					++f;
				}if(r[i].b>=r[i].c){
					r[i].t=r[i].c;
					r[i].h=3;
				}else{
					r[i].t=r[i].b;
					r[i].h=2;
				}
			}else{
				if(r[i].b>=r[i].c){
					r[i].f=r[i].b;
					r[i].o=2;
					++e;
				}else{
					r[i].f=r[i].c;
					r[i].o=3;
					++f;
				}if(r[i].a>=r[i].c){
					r[i].t=r[i].c;
					r[i].h=3;
				}else{
					r[i].t=r[i].a;
					r[i].h=1;
				}
			}r[i].w=6-r[i].h-r[i].o;
			r[i].s=r[i].a+r[i].b+r[i].c-r[i].f-r[i].t;
			r[i].x=r[i].f-r[i].s;
			s+=r[i].f;
		}while(d>m){
			l=1e9;
			for(int i=1;i<=n;i++){
				if(r[i].o==1&&l>r[i].x){
					l=r[i].x;
					g=i;
				}
			}s-=l;
			d--;
			swap(r[g].o,r[g].w);
		}while(e>m){
			l=1e9;
			for(int i=1;i<=n;i++){
				if(r[i].o==2&&l>r[i].x){
					l=min(r[i].x,l);
					g=i;
				}
			}s-=l;
			e--;
			swap(r[g].o,r[g].w);
		}while(f>m){
			l=1e9;
			for(int i=1;i<=n;i++){
				if(r[i].o==3&&l>r[i].x){
					l=min(r[i].x,l);
					g=i;
				}
			}s-=l;
			f--;
			swap(r[g].o,r[g].w);
		}cout<<s<<"\n";
	}
	return 0;
}
