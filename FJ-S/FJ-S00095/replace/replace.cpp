#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s1[5000010];
string s2[5000010];
int main() {
	ios::sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(long long i=1; i<=n; i++)
		cin>>s1[i]>>s2[i];
	for(long long i=1; i<=m; i++) {
		int ans=0;
		string df,fg;
		cin>>df>>fg;
		for(long long j=1; j<=n; j++) {
			int g=df.find(s1[j]);
			int h=df.size();
			if(df.find(s1[j])<=df.size()) {
				string gs="";
				for(long long k=0; k<g; k++) {
					gs+=df[k];
				}
				gs+=s2[j];
				for(long long k=g+s2[j].size(); k<h; k++) {
					gs+=df[k];
				}
				if(gs==fg) {
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}






























