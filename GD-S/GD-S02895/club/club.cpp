#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N][4],q[4][N],t[4],b[N],as;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int i,c1,mx,p;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		t[1]=t[2]=t[3]=0;
		for(as=0,i=1;i<=n;++i){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
				q[1][++t[1]]=i;
			}
			else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
				q[2][++t[2]]=i;
			}
			else if(a[i][3]>a[i][1]&&a[i][3]>a[i][2]){
				q[3][++t[3]]=i;
			}
			as+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		mx=max(t[1],max(t[2],t[3]));
		if(mx<=n/2){
			printf("%d\n",as);
			continue;
		}
		else{
			if(t[1]==mx){
				c1=1;
			}
			else if(t[2]==mx){
				c1=2;
			}
			else{
				c1=3;
			}
			//printf("%d %d\n",c1,mx);
			for(i=1;i<=mx;++i){
				p=q[c1][i];
				if(c1==1){
					b[i]=a[p][1]-max(a[p][2],a[p][3]);
				}
				else if(c1==2){
					b[i]=a[p][2]-max(a[p][1],a[p][3]);
				}
				else{
					b[i]=a[p][3]-max(a[p][1],a[p][2]);
				}
			}
			sort(b+1,b+mx+1);
			/*
			for(i=1;i<=mx;++i){
				printf("%d ",b[i]);
			}
			*/
			//printf("as=%d,mx=%d\n",as,mx);
			for(i=1;mx>n/2;++i){
				as-=b[i];
				//printf("as=%d\n",as);
				--mx;
			}
			printf("%d\n",as);
		}
	} 
	return 0;
} 
