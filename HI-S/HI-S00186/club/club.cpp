#include <bits/stdc++.h>
using namespace std;
struct node{
	int x, y, z;
};
int t, n, a[100010], b[100010], c[100010];
int mx;
long long num;
long long dp[100010][5];//dp[i][j] 第i个人参加j部门的最大满意度
node f[100010][5];//f[i][j] 第i个人加入后的满员情况 
void init(){
	for(int i=0;i<=n;i++){
		for(int j=1;j<=3;j++){
			dp[i][j]=0;
			f[i][j].x=n/2;
			f[i][j].y=n/2;
			f[i][j].z=n/2;
		}
	}
	mx=0;
	num=0;
	return ;
}
long long lst=0;
void solve(int id, int d1, int d2, int d3, long long as){
	if(id>n){
		lst=max(lst, as);
		return ;
	}
	if(d1>0){
		solve(id+1, d1-1, d2, d3, as+a[id]);
	}
	if(d2>0){
		solve(id+1, d1, d2-1, d3, as+b[id]);
	}
	if(d3>0){
		solve(id+1, d1, d2, d3-1, as+c[id]);
	}
	return ;
}
struct node2{
	int v, w;
};
node2 h[100010];
bool cmp(node2 num1, node2 num2){
	if(num1.v!=num2.v)return num1.v>num2.v;
	return num1.w<num2.w;
}
void solve2(){
	for(int i=1;i<=n;i++){
		h[i].v=a[i];
		h[i].w=b[i];
	}
	sort(h+1, h+1+n, cmp);
	lst=0;
	for(int i=1;i<=n;i++){
		if(i<=n/2)lst+=h[i].v;
		else lst+=h[i].w;
		swap(h[i].v, h[i].w);
	}
	long long kk=0;
	sort(h+1, h+1+n, cmp);
	for(int i=1;i<=n;i++){
		if(i<=n/2)kk+=h[i].v;
		else kk+=h[i].w;
	}
	lst=max(lst, kk);
	return ;
}
int main(){
//	freopen("club2.in", "r", stdin);
//	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	int op;
	while(t--){
		scanf("%d", &n);
		int flag=-1, flag2=-1;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d", &a[i], &b[i], &c[i]);
			if(c[i]!=0){
				flag=1;
			}
			if(b[i]!=0){
				flag2=1;
			}
		}
		if(n<=20){
			lst=0;
			solve(1, n/2, n/2, n/2, 0);
			printf("%lld\n", lst);
			continue;
		}
		if(flag==-1&&flag2!=-1){
			lst=0;
			solve2();
			printf("%lld\n", lst);
			continue;
		}
		if(flag==-1&&flag2==-1){
			sort(a+1, a+1+n);
			lst=0;
			int nm=n/2;
			for(int i=n;i>nm;i--){
				lst+=a[i];
			}
			cout<<lst<<endl;
			continue;
		}
		init();
		for(int i=1;i<=n;i++){
			if(i==1){
				dp[i][1]=a[i];
				dp[i][2]=b[i];
				dp[i][3]=c[i];
				f[i][1].x-=1;
				f[i][2].y-=1;
				f[i][3].z-=1;
				continue;
			}
			for(int j=1;j<=3;j++){
				if(j==1)op=a[i];
				if(j==2)op=b[i];
				if(j==3)op=c[i];
				mx=j;
				
				if(i!=1){
					mx=-1;
					num=0; 
					for(int k=1;k<=3;k++){
						if((j==1&&f[i-1][k].x<=0)||(j==2&&f[i-1][k].y<=0)||(j==3&&f[i-1][k].z<=0)){
							if(dp[i-1][k]>num){
								num=dp[i-1][k];
								mx=k;
							}
							continue;
						}
						if(dp[i-1][k]+op>num){
							num=dp[i-1][k]+op;
							mx=k;
						}
					}
				}
				
				dp[i][j]=num;
				
				f[i][j].x=f[i-1][mx].x;
				f[i][j].y=f[i-1][mx].y;
				f[i][j].z=f[i-1][mx].z;
				
				if(j==1&&f[i][j].x>0)f[i][j].x-=1;
				if(j==2&&f[i][j].y>0)f[i][j].y-=1;
				if(j==3&&f[i][j].z>0)f[i][j].z-=1;
			}
		}
		long long ans=-1;
		for(int i=1;i<=3;i++){
			if(ans==-1){
				ans=dp[n][i];
			}else{
				ans=max(ans, dp[n][i]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
