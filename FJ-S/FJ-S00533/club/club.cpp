#include <bits/stdc++.h>
using namespace std;
int t,n,midr,ar,br,cr;
long long zh;
struct st{
	int a;
	int b;
	int c;
};
st z[100005];
st a[100005];
st b[100005];
st c[100005];
bool cnt1(st x,st y){
	return max(x.b-x.a,x.c-x.a)<max(x.b-x.a,x.c-x.a);
}
bool cnt2(st x,st y){
	return max(x.a-x.b,x.c-x.b)<max(x.a-x.b,x.c-x.b);	
}
bool cnt3(st x,st y){
	return max(x.b-x.c,x.a-x.c)<max(x.b-x.c,x.a-x.c);	
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		zh=0;ar=0;br=0;cr=0;
		cin>>n;
		midr=n/2;
		for(int i=1;i<=n;i++){
			cin>>z[i].a>>z[i].b>>z[i].c;
		if(z[i].a>=z[i].b&&z[i].a>=z[i].c){
			ar++;
			a[ar].a=z[i].a;
			a[ar].b=z[i].b;
			a[ar].c=z[i].c;
		}
		if(z[i].a<z[i].b&&z[i].b>=z[i].c){
			br++;
			b[br].a=z[i].a;
			b[br].b=z[i].b;
			b[br].c=z[i].c;
		}
		if(z[i].a<z[i].c&&z[i].b<z[i].c){
			cr++;
			c[cr].a=z[i].a;
			c[cr].b=z[i].b;
			c[cr].c=z[i].c;
		}
		z[i].a=0,z[i].b=0,z[i].c=0;
		}
		
		sort(a+1,a+ar+1,cnt1);
		sort(b+1,b+br+1,cnt2);
		sort(c+1,c+cr+1,cnt3);
		while(ar>midr||br>midr||cr>midr){
			if(ar>midr){
				for(int i=ar;ar>midr;ar--){
					if(a[i].b-a[i].a>=a[i].c-a[i].a){
						br++;
						b[br].a=a[i].a;
						b[br].b=a[i].b;
						b[br].c=a[i].c;
						sort(b+1,b+br+1,cnt2);
					}else{
						cr++;
						c[cr].a=a[i].a;
						c[cr].b=a[i].b;
						c[cr].c=a[i].c;
						sort(c+1,c+cr+1,cnt3);
					}
				}
			}
			if(br>midr){
				for(int i=br;br>midr;br--){
					if(b[i].a-b[i].b>=b[i].c-b[i].b){
						ar++;
						a[ar].a=b[i].a;
						a[ar].b=b[i].b;
						a[ar].c=b[i].c;
						sort(a+1,a+ar+1,cnt1);
					}else{
						cr++;
						c[cr].a=b[i].a;
						c[cr].b=b[i].b;
						c[cr].c=b[i].c;
						sort(c+1,c+cr+1,cnt3);
					}
				}
			}
			if(cr>midr){
				for(int i=cr;cr>midr;cr--){
					if(c[i].b-c[i].c>=c[i].a-c[i].c){
						br++;
						b[br].a=c[i].a;
						b[br].b=c[i].b;
						b[br].c=c[i].c;
						sort(b+1,b+br+1,cnt2);
					}else{
						ar++;
						a[ar].a=c[i].a;
						a[ar].b=c[i].b;
						a[ar].c=c[i].c;
						sort(a+1,a+ar+1,cnt1);
					}
				}
			}
		}
		for(int j=1;j<=ar;j++){
			zh+=a[j].a;
			a[j].a=0,a[j].b=0,a[j].c=0;
		}
		for(int j=1;j<=br;j++){
			zh+=b[j].b;
			b[j].a=0,b[j].b=0,b[j].c=0;
		}
		for(int j=1;j<=cr;j++){
			zh+=c[j].c;
			c[j].a=0,c[j].b=0,c[j].c=0;
		}
		cout<<zh<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
