#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,q;
string sa[MAXN],sb[MAXN];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>sa[i]>>sb[i];
	}
	while(q--){
		string ta,tb;
		cin>>ta>>tb;
		if(ta==tb){
			cout<<0<<"\n";
		}else{
			int ans=0;
			for(int i=0;i<ta.size();i++){
				if(ta[i]!=tb[i]) ans++;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
