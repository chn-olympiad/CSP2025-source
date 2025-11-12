//GZ-S00265 毕节梁才学校 杨文涯杰 
#include<bits/stdc++.h>
using namespace std;
//typedef pair<int,int> PII;
int T,n; 
int a[100000+10][4];
int cont;
struct E{
	int dis1;
	int nee1;
	int dis2;
	int nee2;
	int idx;
};
E d[100000+10];
//E p[100000+10];
//int ma,mi;
//int idx1[100000+10];
//int idx2[100000+10];
bool v1[100000+10];
bool v2[100000+10];
bool cmp1(E x,E y){
	return x.dis1>y.dis1; 
}
bool cmp2(E x,E y){
	return x.dis2>y.dis2;
}
int cnt[5];
int ans;
void init(){
	memset(cnt,0,sizeof(cnt));
	memset(v1,0,sizeof(v1));
	memset(v2,0,sizeof(v2));
	ans=0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d",&n);
		cont=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][2]>=a[i][3]){//1 2 3
				d[i]=(E){a[i][1]-a[i][2],1,a[i][2]-a[i][3],2,i};
			}else if(a[i][2]>=a[i][1]&&a[i][1]>=a[i][3]){//2 1 3
				d[i]=(E){a[i][2]-a[i][1],2,a[i][1]-a[i][3],1,i};
			}else if(a[i][1]>=a[i][3]&&a[i][3]>=a[i][2]){//1 3 2
				d[i]=(E){a[i][1]-a[i][3],1,a[i][3]-a[i][2],3,i};
			}else if(a[i][2]>=a[i][3]&&a[i][3]>=a[i][1]){//2 3 1
				d[i]=(E){a[i][2]-a[i][3],2,a[i][3]-a[i][1],3,i}; 
			}else if(a[i][3]>=a[i][1]&&a[i][1]>=a[i][2]){//3 1 2
				d[i]=(E){a[i][3]-a[i][1],3,a[i][1]-a[i][2],1,i};
			}else if(a[i][3]>=a[i][2]&&a[i][2]>=a[i][1]){//3 2 1
				d[i]=(E){a[i][3]-a[i][2],3,a[i][2]-a[i][1],2,i};
			}
		}
		sort(d+1,d+n+1,cmp1);
		for(int i=1;i<=n;i++){
			if(cnt[d[i].nee1]==cont){
				continue;
			}
			cnt[d[i].nee1]++;
			v1[d[i].idx]=true;
			ans+=a[d[i].idx][d[i].nee1];
		}
		sort(d+1,d+n+1,cmp2);
		for(int i=1;i<=n;i++){
			if(v1[d[i].idx]){
				continue;
			}
			if(cnt[d[i].nee2]==cont){
				cnt[6-d[i].nee1-d[i].nee2]++;
				ans+=a[d[i].idx][6-d[i].nee1-d[i].nee2];
				continue;
			}
			cnt[d[i].nee2]++;
			v2[d[i].idx]=true;
			ans+=a[d[i].idx][d[i].nee2];
		}
		printf("%d\n",ans);
	}
	return 0;
} 
