//GZ-S00255 贵阳市第三中学 杨之尹 
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int a,b,c;
};
struct Q{
	bool a,b,c;
};
Node q[100005];
int T,n,sum=0;
int A[100005],B[100005],C[100005];int ans=0;
int na,nb,nc;
Q vis[100005];
int ma,mb,mc,ai,bi,ci;
void f(int d){
	if(d==n+1){
		ans=max(ans,sum);
		return;
	}
	else{ 
	
		for(int j=1;j<=3;++j){
			if(j==1){
				if(na+1<=n/2){
					na++;
					sum+=q[d].a;
					f(d+1);
					sum-=q[d].a;
					na--;
				}
			
			}else if(j==2){
				if(nb+1<=n/2){
					sum+=q[d].b;
					nb++;
					f(d+1);
					nb--;
					sum-=q[d].b;
					
				}
			}else if(j==3){
				if(nc+1<=n/2){
					nc++;
					sum+=q[d].c;
					f(d+1);
					nc--;
					sum-=q[d].c;
					
				}
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d %d %d",&q[i].a,&q[i].b,&q[i].c);
		}
		f(1);
		printf("%d\n",ans);
		ans=0;
	} 
	return 0;
}
