#include<bits/stdc++.h>
using namespace std;
int T,n,ans;
struct node{
	int x,y,z,v,tg,num;
	const bool operator<(const node x)const {return v<x.v;}
}a[100005];
priority_queue<node>q;
bool vis[100005];
int tag[100005];
int check(int x,int i) {
	if(x==1)return a[i].x;
	if(x==2)return a[i].y;
	return a[i].z;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--) {
		cin>>n,ans=0;
		for(int i=1;i<=n;i++) {
			vis[i]=0,tag[i]=0;
			cin>>a[i].x>>a[i].y>>a[i].z;
			q.push({a[i].x,a[i].y,a[i].z,a[i].x-max(a[i].y,a[i].z),1,i});
			q.push({a[i].x,a[i].y,a[i].z,a[i].y-max(a[i].x,a[i].z),2,i});
			q.push({a[i].x,a[i].y,a[i].z,a[i].z-max(a[i].y,a[i].x),3,i});
		}
		while(!q.empty()) {
			node x=q.top();
			q.pop();
			if(vis[x.num]||tag[x.tg]==n/2)continue;
			vis[x.num]=1,ans+=check(x.tg,x.num),tag[x.tg]++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
