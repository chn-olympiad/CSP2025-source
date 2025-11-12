#include<bits/stdc++.h>
using namespace std;
int n,t;
long long q=0,ji[5],p=0,h=0,hh,hhh,jk[100005];
bool A=true;
struct xh{
	int a;
	int b;
	int c;
	int maxx;
	int type;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		xh like[100005];
		for(int j=0;j<n;j++){
			cin>>like[j].a>>like[j].b>>like[j].c;
            p+=max(like[j].c,max(like[j].a,like[j].b));
            if(like[j].a>=like[j].b&&like[j].a>=like[j].c){
            	like[j].maxx=min(like[j].a-like[j].b,like[j].a-like[j].c);
            	ji[1]++;
            	like[j].type=1;
			}else if(like[j].b>=like[j].a&&like[j].b>=like[j].c){
				like[j].maxx=min(like[j].b-like[j].a,like[j].b-like[j].c);
            	ji[2]++;
            	like[j].type=2;
			}else if(like[j].c>=like[j].b&&like[j].c>=like[j].a){
				like[j].maxx=min(like[j].c-like[j].b,like[j].c-like[j].a);;
            	ji[3]++;
            	like[j].type=3;
			}
		}
		if(ji[1]>n/2){
			for(int j=0;j<n;j++){
				if(like[j].type==1){
					jk[h]=like[j].maxx;
					h++;
				}
			}
			sort(jk,jk+h);
			for(int j=0;j<ji[1]-(n/2);j++){
				p-=jk[j];
			}
		}
		if(ji[2]>n/2){
			for(int j=0;j<n;j++){
				if(like[j].type==2){
					jk[h]=like[j].maxx;
					h++;
				}
			}
			sort(jk,jk+h);
			for(int j=0;j<ji[2]-(n/2);j++){
				p-=jk[j];
			}
		}
		if(ji[3]>n/2){
			for(int j=0;j<n;j++){
				if(like[j].type==3){
					jk[h]=like[j].maxx;
					h++;
				}
			}
			sort(jk,jk+h);
			for(int j=0;j<ji[3]-(n/2);j++){
				p-=jk[j];
			}
		}
		cout<<p<<'\n';
		for(int j=1;j<=3;j++){
			ji[j]=0;
		}
		p=0;
		h=0;
	}
	
	return 0;
}

