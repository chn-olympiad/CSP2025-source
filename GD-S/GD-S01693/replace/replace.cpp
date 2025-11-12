#include<bits/stdc++.h>
using namespace std;
int n,q;
pair<string,string>s[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].first>>s[i].second;
	}
	for(int i=1;i<=q;i++){
		string a,b;
		cin>>a>>b;
		int l=0,ans=0;
		for(int i=1;i<=n;i++){
			if(a.find(s[i].first)<1e18&&b.find(s[i].second)<1e18){
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
