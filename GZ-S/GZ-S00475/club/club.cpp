//GZ-S00475 贵阳市第十九中学 陈瑾南 
#include<bits/stdc++.h>
using namespace std;
int sum;
struct Edge{
	int a1,b2,c3,d,f;
}p[100010];
bool cmp(Edge a,Edge b){
	return a.d<b.d;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,x1=0,y1=0,z1=0,x2,y2,z2;
		cin>>n;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			p[i].a1=a;
			p[i].b2=b;
			p[i].c3=c;
			if(a>=b){
				swap(a,b);
			}
			if(b>=c){
				swap(b,c);
			}
			if(a>=b){
				swap(a,b);
			}
			if(b>=c){
				swap(b,c);
			}
			p[i].d=c-b;
			sum+=c;
			if(c==p[i].a1){
				x1++;
				p[i].f=1;
			}
			else if(c==p[i].b2){
				y1++;
				p[i].f=2;
			}
			else{
				z1++;
				p[i].f=3;
			}
		}
		sort(p+1,p+n+1,cmp);
		if(x1>n/2){
			for(int i=1;i<=n && x1>n/2;i++){
				if(p[i].f==1){
					sum-=p[i].d;
					x1--;
				}
			}
		}
		if(y1>n/2){
			for(int i=1;i<=n && y1>n/2;i++){
				if(p[i].f==2){
					sum-=p[i].d;
					y1--;
				}
			}
		}
		if(z1>n/2){
			for(int i=1;i<=n && z1>n/2;i++){
				if(p[i].f==3){
					sum-=p[i].d;
					z1--;
				}
			}
		}
		cout<<sum<<endl;
		sum=0;
		for(int i=1;i<=n;i++){
			p[i].a1=0;
			p[i].b2=0;
			p[i].c3=0;
			p[i].d=0;
			p[i].f=0;
		}
	}
	return 0;
}
