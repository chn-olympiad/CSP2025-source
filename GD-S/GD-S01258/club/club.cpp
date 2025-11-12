#include<bits/stdc++.h>

using namespace std;

//¶à²âÇå¿Õ 

int t,n;

struct node{
	int x,y,z;
	bool operator <(const node &A)const{
		return x-max(y,z)>A.x-max(A.y,A.z);
	}
}a[100010];

int sum[4];

bool cmp(node a,node b){
	if(a.x!=b.x) return a.x>b.x;
	if(a.y!=b.y) return a.y>b.y;
	return a.z>b.z;
}

int need(node a){
	if(a.x>=a.y&&a.x>=a.z) return 1;
	if(a.y>=a.x&&a.y>=a.z) return 2;
	if(a.z>=a.x&&a.z>=a.y) return 3;
	return 0;
	/*
	if(a.x==a.y&&a.x==a.z) return 4;
	if(a.x==a.y) return 5;
	if(a.x==a.z) return 6;
	if(a.y==a.z) return 7;
	*/
}

priority_queue<node>q[4];

int ans;

int main(){
	
	//freopen("club5.in","r",stdin);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		while(!q[1].empty()) q[1].pop();
		while(!q[2].empty()) q[2].pop();
		while(!q[3].empty()) q[3].pop();
		sum[1]=sum[2]=sum[3]=0;
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			//printf("qwq %d\n",ans);
			int now=need(a[i]);
			int maxn=0;
			int qwq=0;
			
			if(sum[now]>=n/2){
				
				if(now==1){
					maxn=a[i].x;
					if(a[i].y>=a[i].z) qwq=a[i].y;
					else qwq=a[i].z;
				}
				if(now==2){
					maxn=a[i].y;
					if(a[i].x>=a[i].z) qwq=a[i].x;
					else qwq=a[i].z;
				}
				if(now==3){
					maxn=a[i].z;
					if(a[i].x>=a[i].y) qwq=a[i].x;
					else qwq=a[i].y;
				}
				node aaa=q[now].top();
				int ay=aaa.y,az=aaa.z,ax=aaa.x;
				
				//printf("aaaa %d %d %d\n",ax,ay,az);
				
				if(ay>=az){
					if(-ax+ay+maxn>qwq){
						ans+=(-ax+ay+maxn);
						q[now].pop();
						if(now==1) q[1].push((node){a[i].x,a[i].y,a[i].z});
						if(now==2) q[2].push((node){a[i].y,a[i].z,a[i].z});
						if(now==3) q[3].push((node){a[i].z,a[i].y,a[i].x});
					}
					else{
						ans+=qwq;
					}
				}
				else{
					if(-ax+az+maxn>qwq){
						ans+=(-ax+az+maxn);
						q[now].pop();
						if(now==1) q[1].push((node){a[i].x,a[i].y,a[i].z});
						if(now==2) q[2].push((node){a[i].y,a[i].z,a[i].z});
						if(now==3) q[3].push((node){a[i].z,a[i].y,a[i].x});
					}
					else{
						ans+=qwq;
					}
				}
			}
			
			
			else{
				sum[now]++;
				if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
					ans+=a[i].x;
					q[now].push((node){a[i].x,a[i].y,a[i].z});
				}
				else if(a[i].y>=a[i].z&&a[i].y>=a[i].x){
					ans+=a[i].y;
					q[now].push((node){a[i].y,a[i].x,a[i].z});
				}
				else if(a[i].z>=a[i].x&&a[i].z>=a[i].y){
					ans+=a[i].z;
					q[now].push((node){a[i].z,a[i].x,a[i].y});
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
