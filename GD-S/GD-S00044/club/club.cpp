#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct node{
	int a,b;
	int p1,p2;
	int id;
};
node a[100005];
bool cmp(node t1,node t2) {
	return t1.a-t1.b<t2.a-t2.b;
}
int dp[205][205][205];
int val[100005][3];
int temp[4],te[4];
void solve() {
	cin>>n;
//	bool flagA=true;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=3;j++) {
			cin>>val[i][j];
//			cout<<i<<" "<<j<<endl;
		}
		te[1]=val[i][1],te[2]=val[i][2],te[3]=val[i][3];
		temp[1]=te[1],temp[2]=te[2],temp[3]=te[3];
		a[i].id=i;
		sort(temp+1,temp+3+1,greater<int>());
		if(temp[1]==temp[2] && temp[2]==temp[3]) a[i].a=temp[1],a[i].b=temp[2];
		else {
			for(int j=1;j<=3;j++) {
				if(te[j]==temp[1]) a[i].a=j;
			}
			for(int j=1;j<=3;j++) {
				if(te[j]==temp[2]) a[i].b=j;
			}
			if(a[i].a<a[i].b) a[i].a=temp[1],a[i].b=temp[2];
			else a[i].a=temp[2],a[i].b=temp[1];
		}
	}
	int ans=0;
	sort(a+1,a+n+1,cmp);
//	for(int i=1;i<=n;i++) cout<<a[i].a<<" "<<a[i].b<<endl;
	int cnt[4];
	cnt[1]=cnt[2]=cnt[3]=0;
	for(int i=1;i<=n;i++) {
		int pos1=0,pos2=0;
		for(int j=1;j<=3;j++) {
			if(val[a[i].id][j]==a[i].a) pos1=j;
			else if(val[a[i].id][j]==a[i].b) pos2=j;
		}
		if(val[a[i].id][1]==val[a[i].id][2] && val[a[i].id][2]==val[a[i].id][3]) continue;
		if(a[i].a>a[i].b) {
			if(cnt[pos1]<(n/2)) cnt[pos1]++,ans+=a[i].a;
			else cnt[pos2]++,ans+=a[i].b;
		}
		else {
			if(cnt[pos2]<(n/2)) cnt[pos2]++,ans+=a[i].b;
			else cnt[pos1++],ans+=a[i].a;
		}
	}
	cout<<ans<<endl;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;cin>>T;
	while(T--) solve();
	return 0;
} 
