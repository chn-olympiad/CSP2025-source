#include<bits/stdc++.h>
using namespace std;
int t,n,sy[4];
long long ans;
struct sj{
	int a,b,c;
}e[100005];
struct sj2{
	int sz,wz;//shuzhi,weizhi
};
bool cmp(sj aa,sj bb){
	if(max(aa.a,max(aa.b,aa.c))==max(bb.a,max(bb.b,bb.c))){
		int fa[4]={0,aa.a,aa.b,aa.c},fb[4]={0,bb.a,bb.b,bb.c};
		sort(fa+1,fa+4);
		sort(fb+1,fb+4);
		if(fa[2]==fb[2]){
			return fa[3]>fb[3];
		}
		return fa[2]>fb[2];
	}
	return max(aa.a,max(aa.b,aa.c))>max(bb.a,max(bb.b,bb.c));
}
bool cmp2(sj2 xa,sj2 xb){
	return xa.sz>xb.sz;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		memset(sy,0,sizeof(sy));
		scanf("%d",&n);
		int s1=0,s2=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c);
			if(e[i].b!=0) s1=1;
			if(e[i].c!=0) s2=1;
		}
		sort(e+1,e+n+1,cmp);
		if(!s1 && !s2){
			for(int i=1;i<=n/2;i++){
				ans+=e[i].a;
			}
			cout<<ans<<endl;
			continue;
		}
		else if(s2==0){
			for(int i=1;i<=n;i++){
				if(e[i].a>e[i].b && sy[1]<n/2){
					ans+=e[i].a;
					sy[1]++;
				}
				else ans+=sy[2];
			}
			cout<<ans<<endl;
		}
		else{
			queue<int> q[5];
			for(int i=1;i<=n;i++){
				if(e[i].a>e[i].b && sy[1]<n/2){
					ans+=e[i].a;
					sy[1]++;
				}
				else ans+=sy[2];
			}
		}
	}
	return 0;
}
