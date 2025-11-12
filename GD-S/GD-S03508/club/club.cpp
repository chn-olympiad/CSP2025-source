#include<bits/stdc++.h>
using namespace std;
struct gg{
	int e,d1,d2,d3,e2;
}a[100010],b[100010],c[100010];
int t,h[100010][4],v[100010],al,bl,cl,n;
bool bb1(gg x,gg y){
	return x.e>y.e;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int s=0;
		al=0,bl=0,cl=0;
		for(int j=1;j<=n;j++){
			cin>>h[j][1]>>h[j][2]>>h[j][3];
			if(h[j][1]>=h[j][2]&&h[j][1]>=h[j][3]){
				if(h[j][2]>=h[j][3]){
					a[++al].e=h[j][1]-h[j][2];
				}else{
					a[++al].e=h[j][1]-h[j][3];
				}
				s+=h[j][1];
				a[al].e2=j;
				a[al].d1=h[j][1],a[al].d2=h[j][2],a[al].d3=h[j][3];
			}else{
				if(h[j][2]>=h[j][1]&&h[j][2]>=h[j][3]){
					if(h[j][1]>=h[j][3]){
						b[++bl].e=h[j][2]-h[j][1];
					}else{
						b[++bl].e=h[j][2]-h[j][3];
					}
					s+=h[j][2];
					b[bl].e2=j;
					b[bl].d1=h[j][1],b[bl].d2=h[j][2],b[bl].d3=h[j][3];
				}else{
				if(h[j][3]>=h[j][1]&&h[j][3]>=h[j][2]){
					if(h[j][1]>=h[j][2]){
						b[++cl].e=h[j][3]-h[j][1];
					}else{
						b[++cl].e=h[j][3]-h[j][2];
					}				
					s+=h[j][3];
					c[cl].e2=j;
					c[cl].d1=h[j][1],c[cl].d2=h[j][2],c[cl].d3=h[j][3];
					}				
				}			
			}
		}
		int u=n/2;
		if(al<=u&&bl<=u&&cl<=u){
			v[i]=s;
		}else{
			int ao=al>u,bo=bl>u,co=cl>u;
			if(al>u){
				ao=1;
				sort(a+1,a+1+al,bb1);
				for(int k=al;k>u;k--){
					if(a[k].d2>=a[k].d3&&bo==0){
						s-=a[k].d1;
						s+=a[k].d2;
						a[k].e=a[k].d2-a[k].d3;
						al--;
						b[++bl]=a[k];
					}else{
						a[k].e=a[k].d3-a[k].d2;
						s-=a[k].d1;
						s+=a[k].d3;
						al--;
						c[++cl]=a[k];						
					}
				}
			}
			if(bl>u){
				bo=1;
				sort(b+1,b+1+bl,bb1);
				for(int k=bl;k>u;k--){
					if(b[k].d1>=b[k].d3&&ao==0){
						b[k].e=b[k].d1-b[k].d3;
						s-=b[k].d2;
						s+=b[k].d1;
						bl--;
						a[++al]=b[k];
					}else{
						b[k].e=b[k].d3-b[k].d1;
						bl--;
						s-=b[k].d2;
						s+=b[k].d3;
						c[++cl]=b[k];
					}
				}
			}
			if(cl>u){
				co=1;
				sort(c+1,c+1+cl,bb1);
				for(int k=cl;k>u;k--){
					if(c[k].d1>=c[k].d2&&ao==0){
						c[k].e=c[k].d1-c[k].d2;
						s-=c[k].d3;
						s+=c[k].d1;
						cl--;
						a[++al]=c[k];
					}else{
						c[k].e=c[k].d2-c[k].d1;
						cl--;
						b[++bl]=c[k];
						s-=c[k].d3;
						s+=c[k].d2;	
					}
				}
			}
			ao=al>u,bo=bl>u,co=cl>u;
			if(al>u){
				ao=1;
				sort(a+1,a+1+al,bb1);
				for(int k=al;k>u;k--){
					if(a[k].d2>=a[k].d3&&bo==0){
						s-=a[k].d1;
						s+=a[k].d2;
						a[k].e=a[k].d2-a[k].d3;
						al--;
						b[++bl]=a[k];
					}else{
						a[k].e=a[k].d3-a[k].d2;
						s-=a[k].d1;
						s+=a[k].d3;
						al--;
						c[++cl]=a[k];						
					}
				}
			}
			if(bl>u){
				bo=1;
				sort(b+1,b+1+bl,bb1);
				for(int k=bl;k>u;k--){
					if(b[k].d1>=b[k].d3&&ao==0){
						b[k].e=b[k].d1-b[k].d3;
						s-=b[k].d2;
						s+=b[k].d1;
						bl--;
						a[++al]=b[k];
					}else{
						b[k].e=b[k].d3-b[k].d1;
						bl--;
						c[++cl]=b[k];
						s-=b[k].d2;
						s+=b[k].d3;	
					}
				}
			}
			if(cl>u){
				co=1;
				sort(c+1,c+1+cl,bb1);
				for(int k=cl;k>u;k--){
					if(c[k].d1>=c[k].d2&&ao==0){
						c[k].e=c[k].d1-c[k].d2;
						s-=c[k].d3;
						s+=c[k].d1;
						cl--;
						a[++al]=c[k];
					}else{
						c[k].e=c[k].d2-c[k].d1;
						cl--;
						b[++bl]=c[k];
						s-=c[k].d3;
						s+=c[k].d2;	
					}
				}
			}
			v[i]=s;
		}
	}
	for(int i=1;i<=t;i++){
		cout<<v[i]<<"\n";
	}
	return 0;
} 
