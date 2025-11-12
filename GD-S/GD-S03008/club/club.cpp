#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int T;
int n,m;

struct my{
	int a,b,c;
}f[N];

struct node{
	int id,val;
	bool operator < (const node &d)const{
	    return val>d.val;
	}
};

priority_queue<node> q[5];
int cnt[5];

void fp(int id,int x,int y,int z){
	if(x>=y&&x>=z){
		cnt[1]+=x;
		if(q[1].size()+1>m){
			if(x>q[1].top().val){
				q[1].push({id,x});
				id=q[1].top().id;
				y=f[id].b;
				z=f[id].c;
				q[1].pop();
			}
			cnt[1]-=f[id].a;
			if((y>=z&&q[2].size()+1<m)||(z>y&&q[3].size()+1>m)){
	    		cnt[2]+=y;
	    		q[2].push({id,y});
	    		return;
			}else{
				cnt[3]+=z;
				q[3].push({id,z});
				return;
			}
		}
		q[1].push({id,x});
	    return;
	}
	if(y>=x&&y>=z){
		cnt[2]+=y;
		if(q[2].size()+1>m){
			if(y>q[2].top().val){
				q[2].push({id,y});
				id=q[2].top().id;
				z=f[id].c;
				x=f[id].a;
				q[2].pop();
			}
			cnt[2]-=f[id].b;
			if((x>=z&&q[1].size()+1<m)||(z>x&&q[3].size()+1>m)){
	    		cnt[1]+=x;
	    		q[1].push({id,x});
	    		return;
			}else{
				cnt[3]+=z;
				q[3].push({id,z});
				return;
			}
		}
		q[2].push({id,y});
	    return;
	}
	if(z>=x&&z>=y){
		cnt[3]+=z;
		if(q[3].size()+1>m){
			if(z>q[3].top().val){
				q[3].push({id,z});
				id=q[3].top().id;
				y=f[id].b;
				x=f[id].a;
				q[3].pop();
			}
			cnt[3]-=f[id].c;
			if((x>=y&&q[1].size()+1<m)||(y>x&&q[2].size()+1>m)){
	    		cnt[1]+=x;
	    		q[1].push({id,x});
	    		return;
			}else{
				cnt[2]+=y;
				q[2].push({id,y});
				return;
			}
		}
		q[3].push({id,z});
	    return;
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>T;
	while(T--){
		for(int i=1;i<=3;++i) cnt[i]=0;
		while(!q[1].empty()) q[1].pop();
		while(!q[2].empty()) q[2].pop();
		while(!q[3].empty()) q[3].pop();
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;++i){
			cin>>f[i].a>>f[i].b>>f[i].c;
			fp(i,f[i].a,f[i].b,f[i].c);
		}
		int ans=cnt[1]+cnt[2]+cnt[3];
		cout<<ans<<'\n';
	}
	return 0;
}
