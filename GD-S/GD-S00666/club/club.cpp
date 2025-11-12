#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e5+10;
int n,a[N][3],c[3];
int work() {
	cin>>n; 
	for(int j=0;j<3;j++) c[j]=0;
	for(int i=1;i<=n;i++) {
		int mx1=0,mx2=0;
		for(int j=0;j<3;j++) {
			cin>>a[i][j];
			if(a[i][j]>mx2) mx2=a[i][j];
			if(mx2>mx1) swap(mx1,mx2);
		}
		if(mx1>mx2) for(int j=0;j<3;j++) if(a[i][j]==mx1) c[j]++;
	}
	int flag=3;
	for(int i=0;i<3;i++) if(c[i]>n/2) flag=i;
	LL ans=0;
	for(int i=1;i<=n;i++) {
		int mx1=0;
		for(int j=0;j<3;j++) {
			mx1=max(mx1,a[i][j]);
		}
		ans+=mx1;
	}
	if(flag<3) {
//		cout<<flag<<' '<<c[flag]<<' '<<c[flag]-n/2<<'\n';
		vector<int> v;
		for(int i=1;i<=n;i++) {
			int mx1=0,mx2=0;
			for(int j=0;j<3;j++) {
				if(a[i][j]>mx2) mx2=a[i][j];
				if(mx2>mx1) swap(mx1,mx2);
			}
			if(mx1>mx2) for(int j=0;j<3;j++) if(a[i][j]==mx1&&j==flag) v.push_back(mx1-mx2);
		}
		sort(v.begin(),v.end());
//		cout<<v.size()<<'\n';
		for(int i=0;i<c[flag]-n/2;i++) ans-=v[i];
	}
	cout<<ans<<'\n';
	return 0;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;
	cin>>T;
	while(T--) {
		work();
	}
	return 0;
}
