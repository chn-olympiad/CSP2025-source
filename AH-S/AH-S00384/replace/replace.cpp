#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string a[200005],b[200005],x,y,tmp1;
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>a[i]>>b[i];
	}
	while(q--) {
		cin>>x>>y;
		ans=0;
		for(int j=1;j<=n;j++) {
			for(int i=0;i<x.size();i++) {
				if(x.size()-i>=a[j].size()&&x.substr(i,a[j].size())==a[j]) {
					tmp1=x.substr(0,i)+b[j]+x.substr(i+a[j].size(),x.size()+1-i-a[j].size());
					//cout<<tmp1<<" "<<y<<endl;
					if(tmp1==y) {
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
