#include<bits/stdc++.h>
using namespace std;

int T;
int n;
struct Node{
	int x,y,z;
}m[100001];
deque<int> a,b,c;
int sum[4];
int ans;

bool cmp(Node q,Node p){
	if(max(max(q.x,q.y),q.z)==max(max(p.x,p.y),p.z)) return (q.x+q.y+q.z)>(p.x+p.y+p.z);
	return max(max(q.x,q.y),q.z)>max(max(p.x,p.y),p.z);
}

void dfs(int i,int d,int s){
	if(sum[1]>n/2||sum[2]>n/2||sum[3]>n/2){
		return ;
	}
	if(i==n){
		ans=max(ans,s);
		return ;
	}
	i++;
	sum[1]++;
	dfs(i,1,s+m[i].x);
	sum[2]++,sum[1]--;
	dfs(i,1,s+m[i].y);
	sum[3]++,sum[2]--;
	dfs(i,1,s+m[i].z);
	sum[3]--;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		a.clear();
		b.clear();
		c.clear();
		sum[1]=0,sum[2]=0,sum[3]=0;ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>m[i].x>>m[i].y>>m[i].z;
		}
		if(n<=30){
			dfs(0,0,0);
			cout<<ans<<endl;
			continue;
		}
		sort(m+1,m+1+n,cmp);
		for(int i=1;i<=n;i++){
			while(!a.empty()&&m[a.back()].x<m[i].x){
				a.pop_back();
			}
			a.push_back(i);
			while(!b.empty()&&m[b.back()].y<m[i].y){
				b.pop_back();
			}
			b.push_back(i);
			while(!c.empty()&&m[c.back()].z<m[i].z){
				c.pop_back();
			}
			c.push_back(i);
		}
		int xa,xb,xc;
		for(int i=1;i<=n;i++){
			if(!a.empty()){
				xa=a.front();
				if(xa==i&&sum[1]<n/2){
					a.pop_front();
					xa=m[xa].x;
				}
				else xa=0;
			}
			if(!b.empty()){
				xb=b.front();
				if(xb==i&&sum[2]<n/2){
					b.pop_front();
					xb=m[xb].y;
				}
				else xb=0;
			}
			if(!c.empty()){
				xc=c.front();
				if(xc==i&&sum[3]<n/2) {
					c.pop_front();
					xc=m[xc].z;
				}
				else xc=0;
			}
//			if(xa==xb&&xb==xc){
//				if(sum[1]<sum[2]&&sum[1]<sum[3]){
//					
//				}
//			}
			if(xa>xb&&xa>xc){
				sum[1]++;
				ans+=xa;
			}
			else if(xa>xb&&xa==xc){
				if(sum[1]>sum[3]) sum[3]++;
				else sum[1]++;
				ans+=xa;
			}
			else if(xa>xc&&xa==xb){
				if(sum[1]>sum[2]) sum[2]++;
				else sum[1]++;
				ans+=xa;
			}
			
			
			else if(xb>xa&&xb>xc){
				sum[2]++;
				ans+=xb;
			}
			else if(xb>xa&&xb==xc){
				if(sum[2]>sum[3]) sum[3]++;
				else sum[2]++;
				ans+=xb;
			}
			else if(xb>xc&&xb==xa){
				if(sum[2]>sum[1]) sum[1]++;
				else sum[2]++;
				ans+=xb;
			}
			
			
			
			else if(xc>xa&&xc>xb){
				sum[3]++;
				ans+=xc;
			}
			else if(xc>xa&&xc==xb){
				if(sum[3]>sum[2]) sum[2]++;
				else sum[3]++;
				ans+=xc;
			}
			else if(xc>xb&&xc==xa){
				if(sum[3]>sum[1]) sum[1]++;
				else sum[3]++;
				ans+=xc;
			}
		}
		cout<<ans<<endl; 
	}
	return 0;
}
/*
1 
4 
0 1 0 
0 1 0 
0 2 0 
0 2 0
*/
