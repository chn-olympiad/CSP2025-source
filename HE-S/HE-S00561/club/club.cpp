#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int T;
int n,cnt[5],ans;
struct node{
	int x,y,z;
}a[N];
int c[N],tot;
vector<int> pos[5];

void work() {
	ans=tot=0;
	for(int i=1;i<=3;i++) {
		cnt[i]=0;
		pos[i].clear();
	}
	
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i].x>>a[i].y>>a[i].z;
		int now=max(a[i].x,max(a[i].y,a[i].z));
		ans+=now;
		if(now==a[i].x) {
			cnt[1]++;
			pos[1].push_back(i);
		}
		else if(now==a[i].y) {
			cnt[2]++;
			pos[2].push_back(i);
		}
		else if(now==a[i].z) {
			cnt[3]++;
			pos[3].push_back(i);
		}
	}
	if(cnt[1]>n/2) {
		for(auto v:pos[1]) {
			c[++tot]=min(a[v].x-a[v].y,a[v].x-a[v].z);
		}
		sort(c+1,c+tot+1);
		for(int i=1;i<=cnt[1]-n/2;i++) ans-=c[i];
	}
	else if(cnt[2]>n/2) {
		for(auto v:pos[2]) {
			c[++tot]=min(a[v].y-a[v].x,a[v].y-a[v].z);
		}
		sort(c+1,c+tot+1);
		for(int i=1;i<=cnt[2]-n/2;i++) ans-=c[i];
	}
	else if(cnt[3]>n/2) {
		for(auto v:pos[3]) {
			c[++tot]=min(a[v].z-a[v].x,a[v].z-a[v].y);
		}
		sort(c+1,c+tot+1);
		for(int i=1;i<=cnt[3]-n/2;i++) ans-=c[i];
	}
	cout<<ans<<'\n';
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--) work();
	
	return 0;
}
