#include<bits/stdc++.h>
using namespace std;
int n,q,ans,ma;
string s1,s2;
vector<pair<string,string>> a;
map<int,int> m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>s1>>s2;
		int t=s1.size();
		ma=max(ma,t);
		m[t]++;
		a.push_back({s1,s2});
	}
	sort(a.begin(),a.end());
	for(int i=1;i<=q;i++) {
		ans=0;
		cin>>s1>>s2;
		int l=s1.size();
		for(int j=1;j<=ma;j++) {
			if(!m[j]) continue;
			for(int k=0;k<l-j+1;k++) {
				string x=s1.substr(0,k-1),y=s1.substr(k,j),z=s1.substr(k+j-1,l-k-j+1);
				int f=0;
				for(int w=0;w<n;w++) {
					if(f&&a[w].first!=y) break;
					if(a[w].first==y) {
						string t=a[w].second;
						if(x+t+z==s2) 
							ans++;
						f=1;
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
//0 2
1 2
2 2
//3 2
0 5
5
0 2
1 2
2 2
3
*/
