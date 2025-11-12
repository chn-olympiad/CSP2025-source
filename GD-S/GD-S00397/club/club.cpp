#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int read(){
	int z=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		z=z*10+c-'0';
		c=getchar();
	}
	return z;
}
int T,n,cnt[4],ans,sum[N];
struct node{
	int x,i,j;
	bool operator < (const node &y)const{
		return y.x<x;
	}
};
struct ed{
	int x,id;
}a[N][4],b[4];
bool cmp (ed x,ed y){
	return x.x>y.x;
}
priority_queue<node> q[4];
void solve(){
	n=read();
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			b[j].x=read();
			b[j].id=j;
		}
		sort(b+1,b+4,cmp);
		for(int j=1;j<=3;j++){
			a[i][j]=b[j];
		}
	}
	for(int i=1;i<=n;i++){
		int fl=0;
		for(int j=1;j<=2;j++){
			int id=a[i][j].id,eq=a[i][j].x-a[i][j+1].x;
			if(cnt[id]<n/2){
				q[id].push((node){a[i][j].x-a[i][j+1].x,i,j});
				ans+=a[i][j].x;
				cnt[id]++;
				sum[i]=a[i][j].x;
				fl=1;
				break;
			}
			else{
				int topeq=q[id].top().x,topi=q[id].top().i,topj=q[id].top().j;
				if(eq>=topeq){
					q[id].pop();
					q[id].push((node){eq,i,j});
					ans+=a[i][j].x,ans-=topeq;
					sum[i]=a[i][j].x,sum[topi]=a[topi][topj+1].x;
					cnt[a[topi][topj+1].id]++;
					if(topj<2) q[a[topi][topj+1].id].push((node){a[topi][topj+1].x-a[topi][topj+2].x,topi,topj+1});
					fl=1;
					break;
				}
			}	
		}
		if(!fl){
			ans+=a[i][3].x;
			sum[i]=a[i][3].x;
			cnt[a[i][3].id]++;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=3;i++){
		while(!q[i].empty())q[i].pop();
		cnt[i]=0;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
 
