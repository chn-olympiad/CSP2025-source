#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int T,n,m[3],ans,id,id2;
struct node{
	int val[3],ma,mai,ma2,mai2;
}a,p[3][N];
bool cmp(node x,node y){
	return x.ma-x.ma2<y.ma-y.ma2;
}
bool solve(int id,node* q,int m){
	bool res=1;
	sort(q+1,q+1+m,cmp);
	for(int i=1;m-i>=n/2;i++){
		ans-=q[i].ma-q[i].ma2;
		res&=(q[i].mai2!=id2);
	}
	return res;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),id=id2=-1,ans=0;
		for(int i=0;i<3;i++)m[i]=0;
		for(int i=1;i<=n;i++){
			a.ma=a.ma2=-1;
			for(int j=0;j<3;j++){
				scanf("%d",&a.val[j]);
				if(a.val[j]>a.ma)
					a.ma2=a.ma,a.mai2=a.mai,a.ma=a.val[j],a.mai=j;
				else if(a.val[j]>a.ma2)
					a.ma2=a.val[j],a.mai2=j;
			}
			p[a.mai][++m[a.mai]]=a;
			ans+=a.ma;
		}
		for(int i=0;i<3;i++){
			if(m[i]>n/2)id=i;
			if(m[i]==0&&n%2)id2=i;
		}
		if(id!=-1){
			bool vis=solve(id,p[id],m[id]);
			if(vis&&id2!=-1){
				int mi=1e9+1;
				for(int i=0;i<3;i++){
					for(int j=1;j<=m[i];j++){
						if(i==id){
							if(j<=m[i]-n/2)mi=min(mi,p[i][j].ma2-p[i][j].val[id2]);
							else mi=min(mi,p[i][j].ma-p[i][j].val[id2]+(p[id][m[id]-n/2].ma-p[id][m[id]-n/2].ma2));
						}
						else{
							mi=min(mi,p[i][j].ma-p[i][j].val[id2]);
						}
					} 
				}
				ans-=mi;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
