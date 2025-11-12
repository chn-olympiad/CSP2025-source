#include<bits/stdc++.h>
using namespace std;
int t,n,ans,vis[4];
struct node {
	int x,y,z,op;
} a[200001];
int q1[200001],q2[200001],q3[200001];
int cnt1,cnt2,cnt3;
bool cmp1(node x,node y) {
	if(x.op==1&&y.op==1) {
		int w1=min(x.x-x.y,x.x-x.z);
		int w2=min(y.x-y.y,y.x-y.z);
		return w1<w2;
	} else if(x.op==1)return 1;
	else return 0;
}
bool cmp2(node x,node y) {
	if(x.op==2&&y.op==2) {
		int w1=min(x.y-x.x,x.y-x.z);
		int w2=min(y.y-y.x,y.y-y.z);
		return w1<w2;
	} else if(x.op==2)return 1;
	return 0;
}
bool cmp3(node x,node y) {
	if(x.op==3&&y.op==3) {
		int w1=min(x.z-x.x,x.z-x.y);
		int w2=min(y.z-y.x,y.z-y.y);
		return w1<w2;
	} else if(x.op==3)return 1;
	else return 0;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>t;
	while(t--) {
		memset(vis,0,sizeof vis);
		ans=0;
		cin>>n;
		for(int i=1; i<=n; i++)
			cin>>a[i].x>>a[i].y>>a[i].z;
		for(int i=1; i<=n; i++) {
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z) {
				vis[1]++;
				ans+=a[i].x;
				a[i].op=1;
			} else if(a[i].y>=a[i].x&&a[i].y>=a[i].z) {
				vis[2]++;
				ans+=a[i].y;
				a[i].op=2;
			} else if(a[i].z>=a[i].x&&a[i].z>=a[i].y) {
				vis[3]++;
				ans+=a[i].z;
				a[i].op=3;
			}
		}
		if(vis[1]>n/2) {
			int sp = vis[1] - n/2;
			sort(a+1,a+n+1,cmp1);
			for(int i=1; i<=sp; i++)ans-=min(a[i].x-a[i].y,a[i].x-a[i].z);
		} 
		if(vis[2]>n/2) {
			int sp = vis[2] - n/2;
			sort(a+1,a+n+1,cmp2);
			for(int i=1; i<=sp; i++)ans-=min(a[i].y-a[i].x,a[i].y-a[i].z);
		}
		if(vis[3]>n/2) {
			int sp = vis[3] - n/2;
			sort(a+1,a+n+1,cmp3);
			for(int i=1; i<=sp; i++)ans-=min(a[i].z-a[i].x,a[i].z-a[i].y);
		}
		cout<<ans<<endl;
	}
	return 0;
}
