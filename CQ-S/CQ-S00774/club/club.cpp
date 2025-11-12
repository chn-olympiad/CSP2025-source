#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define N 100005
using namespace std;
struct inf{
	ll x,y;
	bool operator <(const inf &z)const{return y>z.y;}
}t;
ll T,n,a[N][4],jl[4],bj[N],ans;
priority_queue<inf>q;
int main(){
	IOS;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n,ans=0;
		memset(jl,0,sizeof jl);
		memset(bj,0,sizeof bj);
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			ll x=a[i][1],y=a[i][2],z=a[i][3];
			if(x>=y&&x>=z)bj[i]=1,jl[1]++;
			else if(y>=x&&y>=z)bj[i]=2,jl[2]++;
			else if(z>=x&&z>=y)bj[i]=3,jl[3]++;
		}if(jl[1]>n/2){
			while(!q.empty())q.pop();
			for(int i=1;i<=n;i++)
				if(bj[i]==1)
					q.push({i,a[i][1]-max(a[i][2],a[i][3])});
			while(jl[1]>n/2){
				jl[1]--,t=q.top(),q.pop();
				if(a[t.x][2]>=a[t.x][3])bj[t.x]=2;
				else bj[t.x]=3;
			}
		}if(jl[2]>n/2){
			while(!q.empty())q.pop();
			for(int i=1;i<=n;i++)
				if(bj[i]==2)
					q.push({i,a[i][2]-max(a[i][1],a[i][3])});
			while(jl[2]>n/2){
				jl[2]--,t=q.top(),q.pop();
				if(a[t.x][1]>=a[t.x][3])bj[t.x]=1;
				else bj[t.x]=3;
			}
		}if(jl[3]>n/2){
			while(!q.empty())q.pop();
			for(int i=1;i<=n;i++)
				if(bj[i]==3)
					q.push({i,a[i][3]-max(a[i][1],a[i][2])});
			while(jl[3]>n/2){
				jl[3]--,t=q.top(),q.pop();
				if(a[t.x][1]>=a[t.x][2])bj[t.x]=1;
				else bj[t.x]=2;
			}
		}
		for(int i=1;i<=n;i++)ans+=a[i][bj[i]];
		cout<<ans<<"\n";
	}
	return 0;
}
