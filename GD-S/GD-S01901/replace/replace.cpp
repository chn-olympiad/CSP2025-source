#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,q;
pair<string,string> s[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].first>>s[i].second;
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		string aa=a;
		int ans=0;
		for(int i=1;i<=n;i++){
			aa=a;
			int k=a.find(s[i].first);
//			cout<<k<<" ";
			if(k<a.size()&&k>=0){
				for(int j=0;j<s[i].second.size();j++){
					aa[k+j]=s[i].second[j];
				}
			}
//			cout<<i<<" "<<aa<<" ";
			if(aa==b){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
