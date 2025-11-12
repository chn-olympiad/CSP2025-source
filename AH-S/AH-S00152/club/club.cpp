#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct Node{int a,b,c,d;}A[N],B[N],C[N];
int t,n,a,b,c,ans;
bool cmp(Node x,Node y){return x.d<y.d;}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
	    scanf("%d",&n);
	    a=b=c=ans=0;
	    for(int x,y,z,i=1;i<=n;i++){
		    scanf("%d%d%d",&x,&y,&z);
		    int Max=max(x,max(y,z)); ans+=Max;
		    if(Max==x) A[++a].a=x,A[a].b=y,A[a].c=z,A[a].d=x-max(y,z);
		    else if(Max==y) B[++b].a=x,B[b].b=y,B[b].c=z,B[b].d=y-max(x,z);
		    else C[++c].a=x,C[c].b=y,C[c].c=z,C[c].d=z-max(x,y);
		}
		int m=max(a,max(b,c));
		if(m<=n/2){
		    printf("%d\n",ans);
		    continue;
		}
		if(m==a) sort(A+1,A+a+1,cmp);
		if(m==b) sort(B+1,B+b+1,cmp);
		if(m==c) sort(C+1,C+c+1,cmp);
		for(int i=1;i<=m-n/2;i++){
		    if(m==a) ans-=A[i].d;
		    if(m==b) ans-=B[i].d;
		    if(m==c) ans-=C[i].d;
		}
		printf("%d\n",ans);
	}
    return 0;
}
