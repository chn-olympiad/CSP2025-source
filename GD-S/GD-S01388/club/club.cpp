#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int T,n,ans;
int st[6],a[N][6];
vector<int> g;
struct node{
	int u,v,w;
	bool operator <(const node& x)const{
		return this->w>x.w;
	}
};
priority_queue<node> q1,q2;
int in(){
	int f=1,ans=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c==45)
			f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		ans=ans*10+c-48;
		c=getchar();
	}
	return f*ans;
}
void dfs(int x,int s){
	if(x==n){
		ans=max(ans,s);
		return;
	}
	for(int i=0;i<3;++i){
		++st[i];
		if(st[i]<=n/2)
			dfs(x+1,s+a[x][i]);
		--st[i];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=in();
	bool b,c;
	while(T--){
		n=in();ans=0;
		b=c=1;
		for(int i=0;i<n;++i){
			for(int j=0;j<3;++j){
				a[i][j]=in();
				if(b&&j==1&&a[i][j])
					b=0;
				if(c&&j==2&&a[i][j])
					c=0;
			}
		}
		if(c){
			if(b){
				for(int i=0;i<n;++i)
					g.push_back(a[i][0]);
				sort(g.begin(),g.end(),greater<int>());
				for(int i=0;i<n/2;++i)
					ans+=g[i];
				g.clear();
			}
			else{
				for(int i=0;i<n;++i){
					if(a[i][0]>a[i][1]){
						if(q1.size()<n/2)
							q1.push({a[i][0],a[i][1],a[i][0]-a[i][1]});
						else{
							node t=q1.top();
							if(a[i][0]+t.v>a[i][1]+t.u){
								q1.pop();q2.push(t);
								q1.push({a[i][0],a[i][1],a[i][0]-a[i][1]});
							}
							else
								q2.push({a[i][0],a[i][1],INT_MAX});
						}
					}
					else{
						if(q2.size()<n/2)
							q2.push({a[i][0],a[i][1],a[i][1]-a[i][0]});
						else{
							node t=q2.top();
							if(a[i][1]+t.u>a[i][0]+t.v){
								q2.pop();q1.push(t);
								q2.push({a[i][0],a[i][1],a[i][1]-a[i][0]});
							}
							else
								q1.push({a[i][0],a[i][1],INT_MAX});
						}
					}
				}
				while(q1.size()){
					ans+=q1.top().u;
					q1.pop();
				}
				while(q2.size()){
					ans+=q2.top().v;
					q2.pop();
				}
			}
		}
		else
			dfs(0,0);
		printf("%d\n",ans);
	} 
	return 0;
}
