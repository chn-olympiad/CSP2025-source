#include<bits/stdc++.h>
using namespace std;
struct w{
	int x,y;
};
struct abc{
	w q[4];
}a[105000];
bool cmpp(w x,w y){
	return x.y>y.y;
}
bool cmp(abc x,abc y){
	return x.q[1].y>y.q[1].y;
}
int n,n2;
int sum[4],us[4],ans;
int ansi;
int jie,nn[4];
void dfs(int x){
	if(x==n+1){
		if(ans<sum[1]+sum[2]+sum[3]) ansi++;
		ans=max(ans,sum[1]+sum[2]+sum[3]);
		return;
	}
	if(ansi==jie) return;
	for(int i=1;i<=3;i++){
		if(us[a[x].q[i].x]<n2){
			us[a[x].q[i].x]++;
			sum[a[x].q[i].x]+=a[x].q[i].y;
			dfs(x+1);
			us[a[x].q[i].x]--;
			sum[a[x].q[i].x]-=a[x].q[i].y;
		}
			
	}
}
void dfs2(int x){
	if(x==n+1){
		if(ans<sum[1]+sum[2]) ansi++;
		ans=max(ans,sum[1]+sum[2]);
		return;
	}
	if(ansi==jie) return;
	for(int i=1;i<=2;i++){
		if(us[a[x].q[i].x]<n2){
			us[a[x].q[i].x]++;
			sum[a[x].q[i].x]+=a[x].q[i].y;
			dfs(x+1);
			us[a[x].q[i].x]--;
			sum[a[x].q[i].x]-=a[x].q[i].y;
		}
			
	}
}
void work(){
	ansi=0;memset(sum,0,sizeof(sum));
	memset(us,0,sizeof(us));memset(nn,0,sizeof(nn));
	ans=0;
	cin>>n;
	n2=n/2;
	bool o23=1,o3=1;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].q[1].y,&a[i].q[2].y,&a[i].q[3].y);
		a[i].q[1].x=1;a[i].q[2].x=2;a[i].q[3].x=3;
		if(a[i].q[3].y!=0) o3=0;
		if(a[i].q[3].y!=0||a[i].q[2].y!=0) o23=0;
		sort(a[i].q+1,a[i].q+4,cmpp);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		nn[a[i].q[1].x]++;
	}
	jie=max(0,(n2-nn[1]))+max(0,(n2-nn[2]))+max(0,(n2-nn[3]));
	jie+=2;
	if(o23){
		int suu=0;
		for(int i=1;i<=n2;i++){
			suu+=a[i].q[1].y;
		}
		cout<<suu;
	}else if(o3){
		dfs2(1);
	}else dfs(1);
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int ttt;
	cin>>ttt;
	for(int ttti=1;ttti<=ttt;ttti++) work();
	return 0;
}
