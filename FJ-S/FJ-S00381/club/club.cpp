#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
struct code{
	int s;
	int l;
	int e=0;
}a[N],b[N],c[N];
int sum,aa,bb,cc;
bool cmp(code x,code y){
	return x.s>y.s;
}
void f(code a[],code b[],code c[],int ll,int n){
	for(int i=1;i<=n;i++){
		if(a[i].l==ll){
			a[i].e=1;
		} 
		if(b[i].l==ll){
			b[i].e=1;
		} 
		if(c[i].l==ll){
			c[i].e=1;
		}
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		sum=0;
		aa=0;bb=0;cc=0;
		cin>>n;
		for(int j=1;j<=n;j++){
		cin>>a[j].s>>b[j].s>>c[j].s;
		a[j].l=b[j].l=c[j].l=j;
		}	
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		for(int j=1;j<=n;j++){
			if(a[j].l!=b[j].l&&a[j].l!=c[j].l&&b[j].l!=c[j].l){
				aa++;bb++;cc++;sum+=a[j].s+b[j].s+c[j].s;
				if(a[j].e==1){aa--;sum-=a[j].s;}else {f(a,b,c,a[j].l,n);}
				if(b[j].e==1){bb--;sum-=b[j].s;}else {f(a,b,c,b[j].l,n);}
				if(c[j].e==1){cc--;sum-=c[j].s;}else {f(a,b,c,c[j].l,n);}
			}else if(a[j].l==b[j].l&&c[j].l!=a[j].l){
				cc++; sum+=c[j].s;
				if(c[j].e==1){cc--;sum-=c[j].s;}else {f(a,b,c,c[j].l,n);}
				if(a[j].s>b[j].s){
					aa++;sum+=a[j].s;
					if(a[j].e==1){aa--;sum-=a[j].s;}else {f(a,b,c,a[j].l,n);}
				}else if(a[j].s<b[j].s){
					bb++;sum+=b[j].s;
					if(b[j].e==1){bb--;sum-=b[j].s;}else {f(a,b,c,b[j].l,n);}
				}else{
					if(aa<=bb){
						aa++;sum+=a[j].s;
						if(a[j].e==1){aa--;sum-=a[j].s;}else {f(a,b,c,a[j].l,n);}
					}else{
						bb++;sum+=b[j].s;
						if(b[j].e==1){bb--;sum-=b[j].s;}else{f(a,b,c,b[j].l,n);}
					}
				}
				
			}else if(a[j].l==c[j].l&&b[j].l!=a[j].l){
				bb++;sum+=b[j].s;
				if(b[j].e==1){bb--;sum-=b[j].s;}else {f(a,b,c,b[j].l,n);}
				if(a[j].s>c[j].s){
					aa++;sum+=a[j].s;
					if(a[j].e==1){aa--;sum-=a[j].s;}else{f(a,b,c,a[j].l,n);}
				}else if(a[j].s<c[j].s){
					cc++;sum+=c[j].s;
					if(c[j].e==1){cc--;sum-=c[j].s;}else{f(a,b,c,c[j].l,n);}
				}else{
					if(aa<=cc){
						aa++;sum+=a[j].s;
						if(a[j].e==1){aa--;sum-=a[j].s;}else{f(a,b,c,a[j].l,n);}
					}else{
						cc++;sum+=c[j].s;
						if(c[j].e==1){cc--;sum-=c[j].s;}else{f(a,b,c,c[j].l,n);}
					}
				}
				
				
			}else if(c[j].l==b[j].l&&b[j].l!=a[j].l){
				aa++;sum+=a[j].s;
				if(a[j].e==1){aa--;sum-=a[j].s;}else{f(a,b,c,a[j].l,n);}
				if(c[j].s>b[j].s){
					cc++;sum+=c[j].s;
					if(c[j].e==1){cc--;sum-=c[j].s;}else{f(a,b,c,c[j].l,n);}
				}else if(c[j].s<b[j].s){
					bb++;sum+=b[j].s;
					if(b[j].e==1){bb--;sum-=b[j].s;}else{f(a,b,c,b[j].l,n);}
				}else{
					if(cc<=bb){
						cc++;sum+=c[j].s;
						if(c[j].e==1){cc--;sum-=c[j].s;}else{f(a,b,c,c[j].l,n);}
					}else{
						bb++;sum+=b[j].s;
						if(b[j].e==1){bb--;sum-=b[j].s;}else {f(a,b,c,b[j].l,n);}
					}
				}
				
			}else{
				if(a[j].s>=b[j].s&&a[j].s>=c[j].s){
					aa++;sum+=a[j].s;
					if(a[j].e==1){aa--;sum-=a[j].s;}else {f(a,b,c,a[j].l,n);}
				}else if(b[j].s>=a[j].s&&b[j].s>=c[j].s){
					bb++;sum+=b[j].s;
					if(b[j].e==1){bb--;sum-=b[j].s;}else{f(a,b,c,b[j].l,n);}
				}else{
					cc++;sum+=c[j].s;
					if(c[j].e==1){cc--;sum-=c[j].s;}else {f(a,b,c,c[j].l,n);}
				}
			}
		}
		int minn=1e9,jj,kk;
		if(aa>n/2){
			while(aa>n/2){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(a[j].l==b[k].l){
						if(abs(a[j].s-b[k].s)<minn){
							minn=abs(a[j].s-b[k].s);
							jj=j;kk=k;
							break;
						}
					}
				}
			}
			aa--;
			sum-=minn;
			}
		}
		cout<<sum<<endl; 
		for(int j=1;j<=n;j++){
			a[j].e=b[j].e=c[j].e=0;
		}
	}
	return 0;
} 

