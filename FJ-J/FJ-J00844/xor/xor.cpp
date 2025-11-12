#include<bits/stdc++.h>
using namespace std;
long long cc,gg=0,aa,a,b,c,d,e,g=0,h=1,i,j,k[1000004],f[1000004];
long long t[1000000];
struct qq{
	int r;
	int l;
};
qq p[700000];
bool ww(qq x,qq y){
	return(x.r<y.r);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	for(i=1;i<=a;i++){
		cin>>k[i];
		if(k[i]>1){
			h=0;
		}
	}
	if(a<=2){
		if(a==1){
			c=k[1];
			if(c==b){
				g++;
			}
		}else{
			c=k[1]^k[2];
			if(c==b){
				g++;
			}
			if(k[1]==b){
				g++;
			}
			if(k[2]==b){
				g++;
			}
		}
	}else{
		if(h==1){
		for(i=1;i<=a;i++){
			f[i]=k[i];
			if(i!=1){
				f[i]=f[i]^f[i-1];
			}
			if(f[i]==b){
				f[i]=0;
				g++;
			}
		}	
		}else{
		g=0;
		for(i=1;i<=a;i++){
			h=k[i];
			if(h==b){
				g++;
				p[g].r=i;
				p[g].l=i;
			}else{
				for(j=i+1;j<=a;j++){
					h=h^k[j];
					if(h==b){
						g++;
						p[g].l=i;
						p[g].r=j;
						
						break;
					}
				}
			}
		}
	sort(p+1,p+g+1,ww);
	d=p[1].r;
	aa=1;
	cc=0;
	while(true){
		cc++;
		aa=0;
	for(i=1;i<=g;i++){
		if(p[i].l>d){
			aa=1;
			d=p[i].r;
			gg++;
			break;
		}
	}
	if(aa==0){
		cout<<gg+1;
		return 0;
		break;
	}	
	}
	}
	
	}
	cout<<g;
	return 0;
} 

