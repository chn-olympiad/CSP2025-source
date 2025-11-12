#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,k,ans,m;
struct student{
	int a,b,c;
}e[100005];
struct node{
	int val,id;
	bool operator <(const node&x) const{
		return x.val<val;
	}
};
priority_queue<node> pa,pb,pc;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		k=n/2;
		ans=0;
		memset(e,0,sizeof(e));
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&e[i].a,&e[i].b,&e[i].c);
			if(e[i].a>=e[i].b&&e[i].a>=e[i].c){
				pa.push({e[i].a-max(e[i].b,e[i].c),i});
				ans+=e[i].a;
			} 
			else if(e[i].b>=e[i].a&&e[i].b>=e[i].c){
				pb.push({e[i].b-max(e[i].a,e[i].c),i});
				ans+=e[i].b;
			} 
			else if(e[i].c>=e[i].a&&e[i].c>=e[i].b){
				pc.push({e[i].c-max(e[i].b,e[i].a),i});
				ans+=e[i].c;
			} 
		}
		while(pa.size()>k){
			node temp=pa.top();
			pa.pop();
			ans-=temp.val;
		}
		while(pb.size()>k){
			node temp=pb.top();
			pb.pop();
			ans-=temp.val;
		}
		while(pc.size()>k){
			node temp=pc.top();
			pc.pop();
			ans-=temp.val;
		}
		while(!pa.empty()) pa.pop();
		while(!pb.empty()) pb.pop();
		while(!pc.empty()) pc.pop();
		printf("%lld\n",ans);
	}
}
