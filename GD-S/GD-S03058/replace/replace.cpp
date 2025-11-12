#include<bits/stdc++.h>
using namespace std;
int n,q;
pair<string,string>s[10005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].first>>s[i].second;
	}
	while(q--){
		string q,w;
		cin>>q>>w;
		int ans=0;
		int c1=q.find('b'),c2=w.find('b');
		for(int i=1;i<=n;i++){
			int t1=s[i].first.find('b'),t2=s[i].second.find('b');
			if(c1+t2-t1==c2)ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
