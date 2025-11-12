#include<bits/stdc++.h>
using namespace std;
int T,n,x,y,z;
vector<array<int,3>> a(100005);
vector<pair<int,int>> s(100005);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		int ans=0;
		map<int,int> m;
		cin>>n;
		int t=(n>>1);
		for(int i=1;i<=n;i++) {
			cin>>x>>y>>z;
			s[i].first=-max(x,max(y,z));
			s[i].second=i;
			a[i]={x,y,z};
		}
		sort(s.begin()+1,s.begin()+1+n);
		for(int i=1;i<=n;i++) {
			int t1=s[i].first,t2=s[i].second;
			t1=-t1;
			x=a[t2][0],y=a[t2][1],z=a[t2][2];
			if(t1==x) {
				if(m[1]<t) {
					ans+=x;
					m[1]++;
				}
				else {
					if(y>z) {
						m[2]++;
						ans+=y;
					}
					else {
						ans+=z;
						m[3]++;
					}
				}
			}
			else if(t1==y) {
				if(m[2]<t) {
					m[2]++;
					ans+=y;
				}
				else {
					if(x>z) {
						ans+=x;
						m[1]++;
					}
					else {
						m[3]++;
						ans+=z;
					}
				}
			}
			else {
				if(m[3]<t) {
					m[3]++;
					ans+=z;
				}
				else {
					if(x>y) {
						m[1]++;
						ans+=x;
					}
					else {
						ans+=y;
						m[2]++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
