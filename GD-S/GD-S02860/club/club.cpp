#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF=0x7fffffff;
const int N=1e5+10;
inline int read(){
	int a=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		a=a*10+c-'0';
		c=getchar();
	}
	return a*f;
}
int t,n;
int sum[4];
int vis[N];
struct node{
	int val,ind;
	bool operator <(const node &x)const{
		return x.val<val;
	}
}a[N][4];
priority_queue<node> q1;
priority_queue<node> q2;
priority_queue<node> q3;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		while(!q3.empty()) q3.pop();
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++){
			a[i][1].val=read();
			a[i][2].val=read();
			a[i][3].val=read();
			a[i][1].ind=1;
			a[i][2].ind=2;
			a[i][3].ind=3;
			sort(a[i]+1,a[i]+4);
			if(a[i][1].ind==1){
				sum[1]+=a[i][1].val;
				q1.push({a[i][1].val-a[i][2].val,i});
			}
			if(a[i][1].ind==2){
				sum[2]+=a[i][1].val;
				q2.push({a[i][1].val-a[i][2].val,i});
			}
			if(a[i][1].ind==3){
				sum[3]+=a[i][1].val;
				q3.push({a[i][1].val-a[i][2].val,i});
			}
			vis[i]=1;
		}
		while(q1.size()>n/2||q2.size()>n/2||q3.size()>n/2){
			if(q1.size()>n/2){
				int u=q1.top().ind;
				q1.pop();
				sum[1]-=a[u][vis[u]].val;
				vis[u]++;
				int x=a[u][vis[u]].ind;
				sum[x]+=a[u][vis[u]].val;
				if(x==2){
					if(vis[u]==3){
						q2.push({INF,u});
					}else{
						q2.push({a[u][vis[u]].val-a[u][vis[u]+1].val,u});
					}
				}else{
					if(vis[u]==3){
						q3.push({INF,u});
					}else{
						q3.push({a[u][vis[u]].val-a[u][vis[u]+1].val,u});
					}
				}
			}else if(q2.size()>n/2){
				int u=q2.top().ind;
				q2.pop();
				sum[2]-=a[u][vis[u]].val;
				vis[u]++;
				int x=a[u][vis[u]].ind;
				sum[x]+=a[u][vis[u]].val;
				if(x==1){
					if(vis[u]==3){
						q1.push({INF,u});
					}else{
						q1.push({a[u][vis[u]].val-a[u][vis[u]+1].val,u});
					}
				}else{
					if(vis[u]==3){
						q3.push({INF,u});
					}else{
						q3.push({a[u][vis[u]].val-a[u][vis[u]+1].val,u});
					}
				}
			}else{
				int u=q3.top().ind;
				q3.pop();
				sum[3]-=a[u][vis[u]].val;
				vis[u]++;
				int x=a[u][vis[u]].ind;
				sum[x]+=a[u][vis[u]].val;
				if(x==1){
					if(vis[u]==3){
						q1.push({INF,u});
					}else{
						q1.push({a[u][vis[u]].val-a[u][vis[u]+1].val,u});
					}
				}else{
					if(vis[u]==3){
						q2.push({INF,u});
					}else{
						q2.push({a[u][vis[u]].val-a[u][vis[u]+1].val,u});
					}
				}
			}
		}
		cout<<sum[1]+sum[2]+sum[3]<<endl;
	}
	return 0;
}
