#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int base=1e6;

struct Node {
	string from,to;
	int l;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	
	int n,q; cin>>n>>q;
	if(q==1||q<=1000) {
		vector<Node>p[27];
		for(int i=0;i<n;i++) {
			string a,b;
			cin>>a>>b;
			p[a[0]-'a'].push_back({a,b,a.size()});
		}
		while(q--) {
			string t1,tar;
			cin>>t1>>tar;
			int siz=t1.size(),lst=0,ans=0;
			for(int i=0;i<siz;i++) {
			lst=(t1[i]==tar[i])?lst:i;
			}
			//cout<<lst<<endl;
			for(int i=0;i<siz;i++) {
				int ch=t1[i]-'a';
				for(int j=0;j<p[ch].size();j++) {
					Node t=p[ch][j];
					if(t.l+i>siz) continue;
					if(t.l+i<lst+1) continue;
					//cout<<t.from<<endl;
					//cout<<t1.substr(i,t.l)<<' '<<tar.substr(i,t.l)<<endl;
					if(t1.substr(i,t.l)==t.from&&tar.substr(i,t.l)==t.to) {
						ans++;
					}
				}
				if(t1[i]!=tar[i]) break;
			}
			cout<<ans<<endl;
		}
	}
	else {
		vector<pair<int,int>>p[base*2];
		for(int i=0;i<n;i++) {
			string a,b;
			cin>>a>>b;
			int b1=-1,b2=-1;
			for(int i=0;i<a.size();i++) {
				if(a[i]=='b') b1=i;
				if(b[i]=='b') b2=i;
			}
			p[base+b2-b1].push_back(make_pair(b1,a.size()));
		}
		while(q--) {
			string t1,tar;
			cin>>t1>>tar;
			int b1=-1,b2=-1,siz=t1.size(),ans=0;
			for(int i=0;i<siz;i++) {
				if(t1[i]=='b') b1=i;
				if(tar[i]=='b') b2=i;
			}
			for(int i=0;i<p[base+b2-b1].size();i++) {
				int l=p[base+b2-b1][i].first,r=p[base+b2-b1][i].second;
				if(b1>=l&&b1+r-l<=siz) ans++;
			}
			cout<<ans<<endl;
		}
	}
	
	return 0;
} 
