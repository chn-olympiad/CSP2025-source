#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int ans=0;
int n;
bool flag;
unsigned long long k;
vector<int> s;
vector<int> f;
vector<bool> vis;
vector<int> r;

namespace kd {
	vector<long long> s;
	vector<long long> f;
}

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d",&n);
	cin>>k;
	if(k>255) {
		kd::s.resize(n+10);
		kd::f.resize(n+10);
		r.resize(n+10);
		vis.resize(n+10);
		for(int i=1;i<=n;i++) {
			scanf("%lld",&kd::s[i]);
			kd::f[i]=kd::f[i-1]^kd::s[i];
		}
		int t;
		for(int i=1;i<=n;i++) {
			for(int j=i;j<=n;j++) {
				if(f[j]^f[i]==k) {
					flag=0;
					ans++;
					for(int k=i;k<=j;k++) {
						if(vis[k]==1) {
							ans--;
							if(r[k]<j) {
								t=r[k];
								flag=1;
							}
							break;
						}
					}
					if(!flag) {
						for(int k=i;k<=j;k++) {
							vis[i]=1;
							r[i]=j;
						}
					}
					if(flag) {
						for(int k=1;k<=n;k++) {
							if(r[k]==t) {
								vis[i]=0;
								r[k]=0;
							}
						}
					}
				}
			}
		}
	} else {
		int t;
		s.resize(n+10);
		f.resize(n+10);
		r.resize(n+10);
		vis.resize(n+10);
		for(int i=1;i<=n;i++) {
			scanf("%d",&s[i]);
			f[i]=f[i-1]^s[i];
		}
		for(int i=1;i<=n;i++) {
			for(int j=i;j<=n;j++) {
				if(f[j]^f[i]==k) {
					flag=0;
					ans++;
					for(int k=i;k<=j;k++) {
						if(vis[k]==1) {
							ans--;
							if(r[k]<j) {
								t=r[k];
								flag=1;
							}
							break;
						}
					}
					if(!flag) {
						for(int k=i;k<=j;k++) {
							vis[i]=1;
							r[i]=j;
						}
					}
					if(flag) {
						for(int k=1;k<=n;k++) {
							if(r[k]==t) {
								vis[i]=0;
								r[k]=0;
							}
						}
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
