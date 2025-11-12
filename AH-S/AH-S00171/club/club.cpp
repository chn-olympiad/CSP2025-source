#include<bits/stdc++.h>
using namespace std;
int t,n,maxn,sumc,sumb,suma;
int a[200005][4],x[200005],f[200005];
struct node{
	int x,id,c,cid;
}ai[200005],bi[200005],ci[200005];
int as,bs,cs;
bool cmp(node l1,node r1){
	return l1.c>r1.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		maxn=0;
		as=0;bs=0;cs=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])f[i]=1,as++,x[i]=a[i][1],ai[as].id=i,ai[as].x=a[i][1];
			if(a[i][2]>a[i][1]&&a[i][2]>a[i][3])f[i]=2,bs++,x[i]=a[i][2],bi[bs].id=i,bi[bs].x=a[i][2];
			if(a[i][3]>a[i][1]&&a[i][3]>a[i][2])f[i]=3,cs++,x[i]=a[i][3],ci[cs].id=i,ci[cs].x=a[i][3];
		}
		for(int i=1;i<=n;i++)maxn+=x[i];
		if(as>n/2||bs>n/2||cs>n/2){
			if(as>n/2){
				for(int i=1;i<=as;i++){
					if((a[ai[i].id][1]-a[ai[i].id][2])<(a[ai[i].id][1]-a[ai[i].id][3])){
						ai[i].c=a[ai[i].id][1]-a[ai[i].id][2];
						ai[i].cid=2;
					}
					else{
						ai[i].c=a[ai[i].id][1]-a[ai[i].id][3];
						ai[i].cid=3;
					}
				}
				sort(ai+1,ai+as+1,cmp);
				while(as>n/2){
					if(ai[as].cid==2){
						bs++;
						bi[bs].x=a[ai[as].id][2];
					}
					else{
						cs++;
						ci[cs].x=a[ai[as].id][3];
					}
					as--;
				}
				//printf("%d %d %d\n",as,bs,cs);
			}
			if(bs>n/2){
				for(int i=1;i<=bs;i++){
					if((a[bi[i].id][2]-a[bi[i].id][1])<(a[bi[i].id][2]-a[bi[i].id][3])){
						bi[i].c=a[bi[i].id][2]-a[bi[i].id][1];
						bi[i].cid=1;
					}
					else{
						bi[i].c=a[bi[i].id][2]-a[bi[i].id][3];
						bi[i].cid=3;
					}
				}
				sort(bi+1,bi+bs+1,cmp);
				while(bs>n/2){
					
					if(bi[bs].cid==1){
						as++;
						ai[as].x=a[bi[bs].id][1];
					}
					else{
						cs++;
						ci[cs].x=a[bi[bs].id][3];
					}
					bs--;
				}
				//printf("%d %d %d\n",as,bs,cs);
			}
			if(cs>n/2){
				for(int i=1;i<=cs;i++){
					if((a[ci[i].id][3]-a[ci[i].id][1])<(a[ci[i].id][3]-a[ci[i].id][2])){
						ci[i].c=a[ci[i].id][3]-a[ci[i].id][1];
						ci[i].cid=1;
					}
					else{
						ci[i].c=a[ci[i].id][3]-a[ci[i].id][2];
						ci[i].cid=2;
					}
				}
				sort(ci+1,ci+cs+1,cmp);
				while(cs>n/2){
					
					if(ci[cs].cid==2){
						bs++;
						bi[bs].x=a[ci[cs].id][2];
					}
					else{
						as++;
						ai[as].x=a[ci[cs].id][1];
					}
					cs--;
				}
			}
			maxn=0;
			for(int i=1;i<=as;i++)maxn+=ai[i].x;
			for(int i=1;i<=bs;i++)maxn+=bi[i].x;
			for(int i=1;i<=cs;i++)maxn+=ci[i].x;
		}
		printf("%d\n",maxn);
	}
	return 0;
}
/*
1
4
10 20 0
30 15 0
100 80 0
5 2 0
*/
