#include<bits/stdc++.h>
using namespace std;
struct node{
	int sum,r,s,t;
}a[100005];
bool cmp(node o,node p){
	return o.sum>p.sum;
}
int Ans=0,n;
void dfs(int P1,int P2,int P3,int u,int su){
	if(u>n){
		Ans=max(Ans,su);
		return;
	}
	if(u>n+1) return;
	if(P1) dfs(P1-1,P2,P3,u+1,su+a[u].r);
	if(P2) dfs(P1,P2-1,P3,u+1,su+a[u].s);
	if(P3) dfs(P1,P2,P3-1,u+1,su+a[u].t);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int q;
	scanf("%d",&q);
	while(q--){
		int sum1=0,sum2=0,sum3=0;
		scanf("%d",&n);
		bool f=0,f1=0;
		for(int i=1; i<=n; i++){
			scanf("%d %d %d",&a[i].r,&a[i].s,&a[i].t);
			a[i].sum=a[i].r+a[i].s+a[i].t;
			sum1+=a[i].r;
			sum2+=a[i].s;
			sum3+=a[i].t;
			if(!(a[i].s==0&&a[i].t==0)){
				f=1;
			}
			if(a[i].t!=0) f1=1;
		}
		if(n==2){
			printf("%d\n",max(a[1].r+a[2].s,max(a[1].r+a[2].t,max(a[1].s+a[2].r,max(a[1].s+a[2].t,max(a[1].t+a[2].r,a[1].t+a[2].s))))));
			continue;
		}
		if(n<=10){
			Ans=0;
			dfs(n/2,n/2,n/2,1,0);
			printf("%d\n",Ans);
			continue;
		}
		long long suma=0;
		if(f==0){
			for(int i=1; i<=n/2; i++){
				suma+=a[i].r;
			}	
			printf("%lld\n",suma);
			continue;
		}
		if(f1==1){
			int P1=n/2,P2=n/2;
			for(int i=1; i<=n; i++){
				if(a[i].s==a[i].r){
					suma+=a[i].s;
				}else if(P2&&a[i].s<a[i].r){
					suma+=a[i].r;
					P2--;
				}else{
					suma+=a[i].s;
					P1--;
				}
			}
			printf("%lld\n",suma);
			continue;
		}
		sort(a+1,a+n+1,cmp);
		int p1=n/2,p2=n/2,p3=n/2;
		for(int i=1; i<=n; i++){
			int m1=a[i].r,m2=a[i].s,m3=a[i].t;
			if(m3>m2){
				swap(m2,m3);
			}
			if(m1<m2){
				swap(m1,m2);
			}
			int id1=0,id2=0,id3=0;
			if(m1==a[i].r){
				id1=1;
			}else if(m1==a[i].s){
				id2=1;
			}else{
				id3=1;
			}
			if(m2==a[i].r){
				if(!id1) id2=2;
			}else if(m2==a[i].s){
				if(!id1) id2=2;
			}else{
				id3=2;
			}
			if(!id1) id1=3;
			if(!id2) id2=3;
			if(!id3) id3=3;
			if(id1==1){
				if(p1){
					p1--;
					suma+=a[i].r;
				}else if(id2==2){
					p2--;
					suma+=a[i].s;
				}else{
					p3--;
					suma+=a[i].t;
				}
			}else if(id2==1){
				if(p2){
					p2--;
					suma+=a[i].s;
				}else if(id1==2){
					p1--;
					suma+=a[i].r;
				}else{
					p3--;
					suma+=a[i].t;
				}
			}else{
				if(p3){
					p3--;
					suma+=a[i].t;
				}else if(id1==2){
					p1--;
					suma+=a[i].r;
				}else{
					p2--;
					suma+=a[i].s;
				}
			}
		}
		printf("%lld\n",suma);
	}
	return 0;
}
