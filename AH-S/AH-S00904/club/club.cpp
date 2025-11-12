#include<bits/stdc++.h>
using namespace std;
int n,t;
struct xss{
	int a,b,c;
}h[100006];
struct sss{
	int ab,x;
}d[200005];
int x[100005],y[100005],z[100005];
bool cmp(sss a,sss b){
	return a.x<b.x; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int q=0,w=0,e=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&h[i].a,&h[i].b,&h[i].c);
			if(h[i].a>=h[i].b&&h[i].a>=h[i].c){
				x[++q]=i;
			}
			else if(h[i].b>=h[i].a&&h[i].b>=h[i].c){
				y[++w]=i;
			}
			else if(h[i].c>=h[i].b&&h[i].c>=h[i].a){
				z[++e]=i;
			}
		}
		int ans=0;
		for(int i=1;i<=q;i++)
			ans+=h[x[i]].a;
		for(int i=1;i<=w;i++)
			ans+=h[y[i]].b;
		for(int i=1;i<=e;i++)
			ans+=h[z[i]].c;
		if(q>n/2){
			int qq=q-n/2;
			for(int i=1;i<=q;i++){
				d[i].x=h[x[i]].a-h[x[i]].b;
				d[i].ab=1;
				d[i+q].x=h[x[i]].a-h[x[i]].c;
				d[i+q].ab=2;
			}
			sort(d+1,d+q*2+1,cmp);
//			for(int i=1;i<=n*2;i++){
//				cout<< d[i].ab<<" "<<d[i].x<<"\n";
//			}
			for(int i=1;qq&&i<=2*q;i++){
				if(d[i].ab==1){
					if(w+1<=n/2)
						w++,ans-=d[i].x,qq--;
				}
				else{
					if(e+1<=n/2) e++,ans-=d[i].x,qq--;
				}
			}
		}
		
		
		else if(w>n/2){
			int ww=w-n/2;
			for(int i=1;i<=w;i++){
				d[i].x=h[y[i]].b-h[y[i]].a;
				d[i].ab=1;
				d[i+w].x=h[y[i]].b-h[y[i]].c;
				d[i+w].ab=2;
			}
//			for(int i=1;i<=n*2;i++){
//				cout<< d[i].ab<<" "<<d[i].x<<"\n";
//			}
//			puts("");
			sort(d+1,d+w*2+1,cmp);
//			for(int i=1;i<=n*2;i++){
//				cout<< d[i].ab<<" "<<d[i].x<<"\n";
//			}
			for(int i=1;ww&&i<=2*w;i++){
				if(d[i].ab==1){
					if(q+1<=n/2)
						q++,ans-=d[i].x,ww--;
				}
				else{
					if(e+1<=n/2) e++,ans-=d[i].x,ww--;
				}
			}
		}
		
		else if(e>n/2){
			int ee=e-n/2;
			for(int i=1;i<=e;i++){
				d[i].x=h[z[i]].c-h[z[i]].a;
				d[i].ab=1;
				d[i+e].x=h[z[i]].c-h[z[i]].b;
				d[i+e].ab=2;
			}
//			for(int i=1;i<=n*2;i++){
//				cout<< d[i].ab<<" "<<d[i].x<<"\n";
//			}
//			puts("");
			sort(d+1,d+e*2+1,cmp);
//			for(int i=1;i<=n*2;i++){
//				cout<< d[i].ab<<" "<<d[i].x<<"\n";
	//		}
			for(int i=1;ee&&i<=2*e;i++){
				if(d[i].ab==1){
					if(w+1<=n/2)
						w++,ans-=d[i].x,ee--;
				}
				else{
					if(q+1<=n/2) q++,ans-=d[i].x,ee--;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
