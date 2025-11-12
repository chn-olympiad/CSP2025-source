#include<bits/stdc++.h>
using namespace std;
int t,n;
int cnt1,cnt2,cnt3,ans;
struct node {
	int x,y,z,name;
} p[100010];
struct node3 {
	int x,name;
};
node3 q1[50010],q2[50010];
void dfs(int a,int b,int c,int step) {
	if(a>n/2||b>n/2||c>n/2)return;
	if(step>=n) {
		ans=max(ans,cnt1+cnt2+cnt3);
		return;
	}
	cnt1+=p[step].x;
	dfs(a+1,b,c,step+1);
	cnt1-=p[step].x;

	cnt2+=p[step].y;
	dfs(a,b+1,c,step+1);
	cnt2-=p[step].y;

	cnt3+=p[step].z;
	dfs(a,b,c+1,step+1);
	cnt3-=p[step].z;
}
bool cmp(node q,node w) {
	return q.x>w.x;
}
bool cmp2(node3 q,node3 w) {
	return q.x>w.x;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		bool v=0,z=0;
		ans=0;
		for(int i=0; i<n; i++) {
			int u,o,l;
			scanf("%d%d%d",&u,&o,&l);
			p[i].x=u,p[i].y=o;
			p[i].z=l,p[i].name=i;
			if(o)v=1;
			if(l)z=1;
		}
		if(!v&&!z) {
			sort(p,p+n,cmp);
			for(int i=0; i<n/2; i++) {
				ans+=p[i].x;
			}
		} else if(!z) {
			for(int i=0; i<n; i++) {
				q1[i].x=p[i].x;
				q1[i].name=i;
				q2[i].x=p[i].y;
				q2[i].name=i;
			}
			sort(q1,q1+n,cmp2);
			sort(q2,q2+n,cmp2);
			bool st[10010];
			for(int i=0; i<n; i++) {
				st[i]=0;
			}
			for(int i=0; i<n; i++) {
				int y=q1[i].name,r=q2[i].name;
				if(!st[y]){
					st[y]=1;
					ans+=q1[i].x;
				}
				if(!st[r]){
					st[r]=1;
					ans+=q2[i].x;
				}
			}
		} else {
			cnt1=0,cnt2=0,cnt3=0;
			dfs(0,0,0,0);
		}
		cout<<ans<<endl;
	}
	return 0;
}
