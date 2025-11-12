#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct mmbr{
	int c1,c2,c3,a1,a2,a3;
}s[100010];
struct node{
	int x,id;
	bool friend operator < (node x,node y){
		return x.x>y.x;
	}
};
priority_queue<node>q[3];
int n,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n;ans=0;
		node b[3];
		for(int i=1;i<=n;i++){
			cin>>b[0].x>>b[1].x>>b[2].x;
			b[0].id=0,b[1].id=1,b[2].id=2;
			sort(b,b+3);
			s[i].c3=b[2].id,s[i].a3=b[2].x;
			s[i].c2=b[1].id,s[i].a2=b[1].x;
			s[i].c1=b[0].id,s[i].a1=b[0].x;
			q[s[i].c1].push({s[i].a1-s[i].a2,i});ans+=s[i].a1;
			if((int)(q[s[i].c1].size())>(n/2)){
				node u=q[s[i].c1].top();q[s[i].c1].pop();
				ans-=u.x;
				q[s[u.id].c2].push({s[u.id].a2-s[u.id].a3,u.id});
			}
		}
		cout<<ans<<"\n";
		for(int i=0;i<3;i++)while(!q[i].empty())q[i].pop();
	}
	return 0;
}//O(tnlogn)
