#include <bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();
	int k=0,l=1;
	while(c>'9'||c<'0'){
		if(c=='-')l=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		k=k*10+(c-'0');
		c=getchar();
	}
	return l*k;
}
int n,t,vis[100010],now[4];
struct node {
	int num,x,r;
	bool operator<(const node& a)const{
		return x<a.x;
	} 
}a,b,c;
priority_queue<node>q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0;
		memset(vis,0,sizeof(vis));
		now[1]=now[2]=now[3]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a.x,&b.x,&c.x);
			a.num=i;
			a.r=1;
			b.num=i;
			b.r=2;
			c.num=i;
			c.r=3;
			q.push(a);
			q.push(b);
			q.push(c);
		}
		for(int i=1;i<=3*n;i++){
			node x=q.top();
			q.pop();
			if(vis[x.num]==0&&now[x.r]<n/2){
				now[x.r]++;
				vis[x.num]=1;
				ans+=x.x;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
