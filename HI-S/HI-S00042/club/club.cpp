#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
const int maxN=1e5+10;
int t,n,a[maxN][5],ans[10],memnum[5],nowans,choosenum;
bool vis[maxN];
void reset1(){
	memset(a,0,sizeof(a));
	memset(memnum,0,sizeof(memnum));
	nowans=0;
}
void init1(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) scanf("%d",&a[i][j]);
}
void solve1(int now,int ti){
	if(now==n+1){
		ans[ti]=std::max(ans[ti],nowans);
		return;
	}
	for(int i=1;i<=3;i++){
		if(memnum[i]==n/2) continue;
		nowans+=a[now][i];
		memnum[i]++;
		solve1(now+1,ti);
		nowans-=a[now][i];
		memnum[i]--;
	}
}
struct opinion{
	long long sat;
	int clu,stu;
	operator < (const opinion& another) const{
		return sat<another.sat||(sat==another.sat&&clu<another.clu);
	}
}a2[3*maxN];
void reset2(){
	memset(a,0,sizeof(a));
	memset(vis,0,sizeof(vis));
	memset(memnum,0,sizeof(memnum));
	choosenum=0;
}
void init2(){
	scanf("%d",&n);
	for(int i=1;i<=3*n;i++){
		scanf("%lld",&a2[i].sat);
		a2[i].clu=(i-1)%3+1;
		a2[i].stu=(i+2)/3;
	}
	std::sort(&a2[1],&a2[3*n+1]);
}
void solve2(int ti){
	for(int i=3*n;i>=1;i--){
		if(choosenum==n) return;
		if(memnum[a2[i].clu]==n/2||vis[a2[i].stu]) continue;
		ans[ti]+=a2[i].sat;
		memnum[a2[i].clu]++;
		vis[a2[i].stu]=true;
		choosenum++;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int ti=1;ti<=t;ti++){
		if(n<=10){
			reset1();
			init1();
			solve1(1,ti);
		}else{
			reset2();
			init2();
			solve2(ti);
		}
	}
	for(int ti=1;ti<=t;ti++) printf("%d\n",ans[ti]);
	return 0;
} 
