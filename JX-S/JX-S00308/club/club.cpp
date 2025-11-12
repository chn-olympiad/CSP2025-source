#include<bits/stdc++.h>
using namespace std;
struct aa{
	int p,q,r,s,t,u,v,w;
};
bool cmp(aa x,aa y){
	return (x.s>y.s)||((x.s==y.s)&&(x.t>y.t));
}
aa a[100010];
int t,n;
int sb;
long su;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int tt=1;tt<=t;tt++){
		cin>>n;
		sb=0;
		a[0].p=0;
		a[0].q=0;
		a[0].r=0;
		su=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].p>>a[i].q>>a[i].r;
			if((a[i].p>=a[i].q)&&(a[i].q>=a[i].r)){
				a[i].u=1;a[i].v=2;
				a[i].s=a[i].p-a[i].q;
				a[i].t=a[i].q-a[i].r;
			}
			if((a[i].p>=a[i].r)&&(a[i].r>a[i].q)){
				a[i].u=1;a[i].v=3;
				a[i].s=a[i].p-a[i].r;
				a[i].t=a[i].r-a[i].q;
			}
			if((a[i].q>a[i].p)&&(a[i].p>=a[i].r)){
				a[i].u=2;a[i].v=1;
				a[i].s=a[i].q-a[i].p;
				a[i].t=a[i].p-a[i].r;
			}
			if((a[i].q>=a[i].r)&&(a[i].r>a[i].p)){
				a[i].u=2;a[i].v=3;
				a[i].s=a[i].q-a[i].r;
				a[i].t=a[i].r-a[i].p;
			}
			if((a[i].r>a[i].p)&&(a[i].p>=a[i].q)){
				a[i].u=3;a[i].v=1;
				a[i].s=a[i].r-a[i].p;
				a[i].t=a[i].p-a[i].q;
			}
			if((a[i].r>a[i].q)&&(a[i].q>a[i].p)){
				a[i].u=3;a[i].v=2;
				a[i].s=a[i].r-a[i].q;
				a[i].t=a[i].q-a[i].p;
			}
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].u==sb)a[i].u=a[i].v;
			if(a[i].u==1){
				if(a[0].p<=(n/2)){
					su=su+a[i].p;
					a[0].p++;
				}
				else{
					su=su+a[i].p-a[i].s;
					sb=1;
				}
				continue;
			}
			if(a[i].u==2){
				if(a[0].q<=(n/2)){
					su=su+a[i].q;
					a[0].q++;
				}
				else{
					su=su+a[i].q-a[i].s;
					sb=2;
				}
				continue;
			}
			if(a[i].u==3){
				if(a[0].r<=(n/2)){
					su=su+a[i].r;
					a[0].r++;
				}
				else{
					su=su+a[i].r-a[i].s;
					sb=3;
				}
				continue;
			}
		}
		cout<<su<<endl;
	}
	return 0;
}
