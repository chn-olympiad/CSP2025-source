#include <bits/stdc++.h>
using namespace std;
namespace yhy{
	const int MAXN=1e5+5;
	#define int long long
	int n;
	int a[MAXN],b[MAXN],c[MAXN];
	priority_queue<int,vector<int>,greater<int> >Q;
	int belong[MAXN];
	int main() {
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
		std::ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		int T;cin>>T;
		while(T--) {
			int ans=0;
			cin>>n;
			int cnt1=0,cnt2=0,cnt3=0;
			for(int i=1;i<=n;i++) {
				cin>>a[i]>>b[i]>>c[i];
				int Maxx=max(a[i],max(b[i],c[i]));
				ans+=Maxx;
				if(a[i]==Maxx) {
					cnt1++;
					belong[i]=1;
					continue;
				}
				if(b[i]==Maxx) {
					cnt2++;
					belong[i]=2;
					continue;
				}
				if(c[i]==Maxx) {
					cnt3++;
					belong[i]=3;
				}
			}
			if(cnt1>n/2) {
				for(int i=1;i<=n;i++) {
					if(belong[i]==1) {
						Q.push(a[i]-max(b[i],c[i]));
					}
				}
				int Need=cnt1-n/2;
				while(Need--) {
					ans-=Q.top();
					Q.pop();
				}
				while(!Q.empty()) {
					Q.pop();
				}
			}
			if(cnt2>n/2) {
				for(int i=1;i<=n;i++) {
					if(belong[i]==2) {
						Q.push(b[i]-max(c[i],a[i]));
					}
				}
				int Need=cnt2-n/2;
				while(Need--) {
					ans-=Q.top();
					Q.pop();
				}
				while(!Q.empty()) {
					Q.pop();
				}
			}
			if(cnt3>n/2) {
				for(int i=1;i<=n;i++) {
					if(belong[i]==3) {
						Q.push(c[i]-max(b[i],a[i]));
					}
				}
				int Need=cnt3-n/2;
				while(Need--) {
					ans-=Q.top();
					Q.pop();
				}
				while(!Q.empty()) {
					Q.pop();
				}
			}
			cout<<ans<<'\n';
		}
		// cout<<"clock:"<<clock()<<'\n';
		return 0;
	}
}
signed main() {
	yhy::main();
	return 0;
}
/*
有没有可能 移动完了过后新产生的 > n/2

答：没有可能，因为移动玩了过后原来的那个是 n/2

14:41 过大样例
*/