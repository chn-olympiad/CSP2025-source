//May all the beauty be blessed.
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define ull unsigned int
using namespace std;
int n,q;
string s1[200010],s2[200010],sl1[200010],sl2[200010];
pii a[200010];

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>sl1[i]>>sl2[i];
	}
	
	for(int i=1;i<=n;i++){
		a[i].fi=sl1[i].size();
		a[i].se=i;
	}
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++){
		s1[i]=sl1[a[i].se];
		s2[i]=sl2[a[i].se];
	}
	
	while(q--){
		string ss,ssl;
		cin>>ss>>ssl;
		
		if(ss.size()!=ssl.size()){
			cout<<0<<'\n';
			continue;
		}
		
		int ma=ss.size();
		for(int i=ssl.size()-1;i>=0;i--){
			if(ssl[i]!=ss[i]){
				ma=i;
				break;
			}
		}
		
		
		int ans=0;
		for(int i=0;i<ss.size();i++){
			if(i&&ss[i-1]!=ssl[i-1]) break;
			for(int j=1;j<=n;j++){
				if(i+s1[j].size()-1>=ssl.size()) break;
				if(i+s1[j].size()-1<ma) continue;
				bool f=0;
				
				for(int k=0;k<s1[j].size();k++){
					if(ss[i+k]!=s1[j][k]){
						f=1;
						break;
					}
					if(ssl[i+k]!=s2[j][k]){
						f=1;
						break;
					}
				}
				
				if(!f) ans++;
			}
		}
		
		cout<<ans<<'\n';
	}
}
/*

*/


