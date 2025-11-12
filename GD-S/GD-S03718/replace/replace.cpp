#include<bits/stdc++.h>
using namespace std;
string sy[int(2e5+5)],se[int(2e5+5)];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>sy[i]>>se[i];
	}
	while(q--){
		int ans=0;
		string s,str;
		cin>>s>>str;
		for(int i=1;i<=n;i++){
			int id=s.find(sy[i]);
//			cout<<id<<'\n';
			if(~id){
				string fb=s;
				fb.erase(id,se[i].size());
				fb.insert(id,se[i]);
				if(fb==str){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
