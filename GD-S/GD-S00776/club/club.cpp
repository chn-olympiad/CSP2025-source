#include <bits/stdc++.h>
using namespace std;
#define int long long
int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=0;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return f?x:-x;
}
int n,ans,sum,k,kk,f[1005][1005];
struct node {
	int x,y,z;
}a[100005];
priority_queue<int>pq;
bool cmp(node a,node b) {
	return a.x-a.y>b.x-b.y;
}
bool cmpp(node a,node b) {
	return a.x-a.z>b.x-b.z;
}
bool cmppp(node a,node b) {
	return a.y-a.z>b.y-b.z;
}
void solve() {
	n=read(),ans=0;
	for(int i = 1;i <= n;i ++) a[i].x=read(),a[i].y=read(),a[i].z=read();
	sort(a+1,a+n+1,cmp),sum=0,k=0,kk=0;
	for(int i = 1;i <= n;i ++) 
		if(a[i].x>=a[i].y) k++,sum+=a[i].x;
		else sum+=a[i].y;
	if(k>n/2) {
		for(int i = 1;i <= k;i ++) pq.push(max(a[i].z-a[i].x,a[i].y-a[i].x));
		for(int i = 1;i <= k-n/2;i ++) sum+=pq.top(),pq.pop(),kk++;
		for(int i = n;i > k;i --) pq.push(max(a[i].z-a[i].y,a[i].x-a[i].y));
	} else {
		for(int i = n;i > k;i --) pq.push(max(a[i].z-a[i].y,a[i].x-a[i].y));
		for(int i = 1;i <= n/2-k;i ++) sum+=pq.top(),pq.pop(),kk++;
		for(int i = 1;i <= k;i ++) pq.push(max(a[i].z-a[i].x,a[i].y-a[i].x));
	}
	while(kk<n/2&&!pq.empty()&&pq.top()>0) sum+=pq.top(),pq.pop(),kk++;
	while(!pq.empty()) pq.pop();
	ans=max(ans,sum);
	sort(a+1,a+n+1,cmpp),sum=0,k=0,kk=0;
	for(int i = 1;i <= n;i ++) 
		if(a[i].x>=a[i].z) k++,sum+=a[i].x;
		else sum+=a[i].z;
	if(k>n/2) {
		for(int i = 1;i <= k;i ++) pq.push(max(a[i].z-a[i].x,a[i].y-a[i].x));
		for(int i = 1;i <= k-n/2;i ++) sum+=pq.top(),pq.pop(),kk++;
		for(int i = n;i > k;i --) pq.push(max(a[i].y-a[i].z,a[i].x-a[i].z));
	} else {
		for(int i = n;i > k;i --) pq.push(max(a[i].y-a[i].z,a[i].x-a[i].z));
		for(int i = 1;i <= n/2-k;i ++) sum+=pq.top(),pq.pop(),kk++;
		for(int i = 1;i <= k;i ++) pq.push(max(a[i].z-a[i].x,a[i].y-a[i].x));
	}
	while(kk<n/2&&!pq.empty()&&pq.top()>0) sum+=pq.top(),pq.pop(),kk++;
	while(!pq.empty()) pq.pop();
	ans=max(ans,sum);
	sort(a+1,a+n+1,cmppp),sum=0,k=0,kk=0;
	for(int i = 1;i <= n;i ++) 
		if(a[i].y>=a[i].z) k++,sum+=a[i].y;
		else sum+=a[i].z;
	if(k>n/2) {
		for(int i = 1;i <= k;i ++) pq.push(max(a[i].x-a[i].y,a[i].z-a[i].y));
		for(int i = 1;i <= k-n/2;i ++) sum+=pq.top(),pq.pop(),kk++;
		for(int i = n;i > k;i --) pq.push(max(a[i].x-a[i].z,a[i].y-a[i].z));
	} else {
		for(int i = n;i > k;i --) pq.push(max(a[i].x-a[i].z,a[i].y-a[i].z));
		for(int i = 1;i <= n/2-k;i ++) sum+=pq.top(),pq.pop(),kk++;
		for(int i = 1;i <= k;i ++) pq.push(max(a[i].x-a[i].y,a[i].z-a[i].y));
	}
	while(kk<n/2&&!pq.empty()&&pq.top()>0) sum+=pq.top(),pq.pop(),kk++;
	while(!pq.empty()) pq.pop();
	ans=max(ans,sum);
	cout << ans << "\n";
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--) solve();
	return 0;
}
