#include<bits/stdc++.h>
using namespace std;
const int N=1e5+6;
int T,n;
struct stu{
	int w[4],mx,cx,j1,j2;
}s[N],club[4][N];
int join1(stu p){
	for(int i=1; i<=3; i++) if(p.w[i]==p.mx) return i;
}
int join2(stu p){
	for(int i=1; i<=3; i++) if(p.w[i]<=p.mx && p.j1!=i && p.w[i]!=min(p.w[1],min(p.w[2],p.w[3]))) return i;
	return (join1(p)+1)%3+1;
}
bool cmp2(stu p,stu q){
	return p.mx-p.cx<q.mx-q.cx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
//		memset(m,0,sizeof(m));
		int a1,a2,a3;
		for(int i=1; i<=n; i++){
			scanf("%d%d%d",&a1,&a2,&a3);
			s[i].w[1]=a1,s[i].w[2]=a2,s[i].w[3]=a3;
			s[i].mx=max(a1,max(a2,a3));
			s[i].j1=join1(s[i]),s[i].j2=join2(s[i]);
			s[i].cx=s[i].w[s[i].j2];
		}
		long long ans=0,cnt[]={0,0,0,0},ov=0;
		for(int i=1; i<=n; i++){
			ans+=s[i].mx;
			club[s[i].j1][++cnt[s[i].j1]]=s[i];
			
		}
		for(int i=1; i<=3; i++) if(cnt[i]>n/2) ov=i;
		if(ov){
			sort(club[ov]+1,club[ov]+cnt[ov]+1,cmp2);
			int m=cnt[ov];
			for(int i=1; i<=m-n/2; i++) ans-=club[ov][i].mx-club[ov][i].cx;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

