#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
	int shu;
}p[50000];
int a1,b1,c1;
int sum[20]={};
int mxa=-1,mxb=-1,mxc=-1;
int t,n;
bool cmp3(node x,node y){//3
	return x.b<y.b;
}
bool cmp2(node x,node y){//2
	return x.c<y.c;
}
bool cmp1(node x,node y){//1
	return x.a<y.a;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	int tn=t;
	while(t--){
		scanf("%d",&n);
		b1=0;
		a1=0;
		c1=0;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
			if(p[i].a>p[i].b && p[i].a>p[i].c){
				a1++;
				sum[t]+=p[i].a;
				p[i].shu=1;
			} 
			if(p[i].b>p[i].a && p[i].b>p[i].c){
				b1++;
				sum[t]+=p[i].b;
				p[i].shu=2;
			} 
			if(p[i].c>p[i].a && p[i].c>p[i].b){
				c1++;
				sum[t]+=p[i].c;
				p[i].shu=3;
			} 
		}
		if(a1>n/2){ //a1
			sort(p,p+n,cmp1);
			for(int i=0;i<=(a1-n/2);i++){
				if(p[i].b>p[i].c && p[i].shu==1 ){
					sum[t]-=p[i].a;
					sum[t]+=p[i].b;
					a1--;
					b1++;
				}
				if(p[i].b<p[i].c && p[i].shu==1 ){
					sum[t]-=p[i].a;
					sum[t]+=p[i].c;
					a1--;
					c1++;
				}			
			}
		}
		if(b1>n/2){  //b1
			sort(p,p+n,cmp2);
			for(int i=0;i<=(b1-n/2);i++){
				if(p[i].a>=p[i].c && p[i].shu==2 ){
					sum[t]-=p[i].b;
					sum[t]+=p[i].a;
					b1--;
					a1++;
				}
				if(p[i].a<p[i].c && p[i].shu==2 ){
					sum[t]-=p[i].b;
					sum[t]+=p[i].c;
					b1--;
					c1++;
				}
			}
		}
		if(c1>n/2){  //c1
			sort(p,p+n,cmp3);
			for(int i=0;i<=(c1-n/2);i++){
				if(p[i].b>=p[i].a && p[i].shu==3 ){
					sum[t]-=p[i].c;
					sum[t]+=p[i].b;
					c1--;
					b1++;
				}
				if(p[i].b<p[i].a && p[i].shu==3 ){
					sum[t]-=p[i].c;
					sum[t]+=p[i].a;
					c1--;
					a1++;
				}			
			}
		}
	}
	for(int i=tn-1;i>=0;i--){
		cout<<sum[i]<<endl;
	}
	return 0;
}

