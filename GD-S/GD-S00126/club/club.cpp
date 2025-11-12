#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N=100005;

struct node{
	int x,y,z,id;
}a[N],g[N];

int t,n;
int mx[N],nmx[N];
int vis[N];

bool cmp1(node x,node y){
	return x.x>y.x;
}bool cmp2(node x,node y){
	return x.y>y.y;
}bool cmp3(node x,node y){
	return x.z>y.z;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdin);
	
	//Êý×éÇå¿Õ£¡£¡£¡ 
	cin>>t;
	while(t--){
		memset(vis,0,sizeof vis);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			mx[i]=max(max(a[i].x,a[i].y),a[i].z);
			if(mx[i]==a[i].x)nmx[i]=max(a[i].y,a[i].z);
			if(mx[i]==a[i].y)nmx[i]=max(a[i].x,a[i].z);
			if(mx[i]==a[i].z)nmx[i]=max(a[i].x,a[i].y);
			a[i].id=i;
		}
		memcpy(g,a,sizeof a);
		priority_queue<pair<int,int>/*,vector<int>,greater<int>*/ > q1,q2,q3;
		int cnt1=0,cnt2=0,cnt3=0;
		
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++){
			if(cnt1>n/2)break;
			if(mx[a[i].id]==g[a[i].id].x&&cnt1<n/2&&!vis[a[i].id]){
				q1.push(make_pair(-(mx[a[i].id]-nmx[a[i].id]),a[i].id));
				cnt1++;
				vis[a[i].id]=1;
			}
		}
		
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++){
			if(cnt2>n/2)break;
			if(mx[a[i].id]==g[a[i].id].y&&cnt2<n/2&&!vis[a[i].id]){
				q2.push(make_pair(-(mx[a[i].id]-nmx[a[i].id]),a[i].id));
				cnt2++;
				vis[a[i].id]=2;
			}
		}
		
		sort(a+1,a+n+1,cmp3);
		for(int i=1;i<=n;i++){
			if(cnt3>n/2)break;
			if(mx[a[i].id]==g[a[i].id].z&&cnt3<n/2&&!vis[a[i].id]){
				q3.push(make_pair(-(mx[a[i].id]-nmx[a[i].id]),a[i].id));
				cnt3++;
				vis[a[i].id]=3;
			}
		}
		
		memcpy(a,g,sizeof g);
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			
			if(q1.size()&&a[i].x-nmx[i]>-q1.top().first&&q1.size()==n/2){
				if(nmx[q1.top().second]==a[q1.top().second].y){
					vis[q1.top().second]=2;
					q2.push(make_pair(-0x3f3f3f3f,q1.top().second));
					q1.pop();
					q1.push(make_pair(-a[i].x-nmx[i],i));
				}
				else if(nmx[q1.top().second]==a[q1.top().second].z){
					vis[q1.top().second]=3;
					q3.push(make_pair(-0x3f3f3f3f,q1.top().second));
					q1.pop();
					q1.push(make_pair(-a[i].x-nmx[i],i));
				}
				vis[i]=1;
			}
			else if(q2.size()&&a[i].y-nmx[i]>-q2.top().first&&q2.size()==n/2){
				if(nmx[q2.top().second]==a[q2.top().second].x){
					vis[q2.top().second]=1;
					q1.push(make_pair(-0x3f3f3f3f,q2.top().second));
					q2.pop();
					q2.push(make_pair(-a[i].x-nmx[i],i));
				}
				else if(nmx[q2.top().second]==a[q2.top().second].z){
					vis[q2.top().second]=3;
					q3.push(make_pair(-0x3f3f3f3f,q2.top().second));
					q2.pop();
					q2.push(make_pair(-a[i].x-nmx[i],i));
				}
				vis[i]=2;
			}
			else if(q3.size()&&a[i].z-nmx[i]>-q3.top().first&&q3.size()==n/2){
				if(nmx[q3.top().second]==a[q3.top().second].x){
					vis[q3.top().second]=1;
					q1.push(make_pair(-0x3f3f3f3f,q3.top().second));
					q3.pop();
					q3.push(make_pair(-a[i].x-nmx[i],i));
				}
				else if(nmx[q3.top().second]==a[q3.top().second].y){
					vis[q3.top().second]=2;
					q2.push(make_pair(-0x3f3f3f3f,q3.top().second));
					q3.pop();
					q3.push(make_pair(-a[i].x-nmx[i],i));
				}
				vis[i]=3;
			}
		}
		
		int sum=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==1){
				sum+=a[i].x;
			}else if(vis[i]==2){
				sum+=a[i].y;
			}else if(vis[i]==3){
				sum+=a[i].z;
			}else{
				if(q1.size()==n/2)sum+=max(a[i].y,a[i].z);
				if(q2.size()==n/2)sum+=max(a[i].x,a[i].z);
				if(q3.size()==n/2)sum+=max(a[i].x,a[i].y);
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
} 
