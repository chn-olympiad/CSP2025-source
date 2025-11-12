#include<bits/stdc++.h>
using namespace std;
int n,q;
string u[200005],v[200005],s,e;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i];
	}
	while(q--){
		cin>>s>>e;
		bool flag=1;
		for(int i=0;i<s.size();i++){
			if(s[i]!='a'&&s[i]!='b'||e[i]!='a'&&e[i]!='b'){
				flag=0;
			}
		}
		if(flag){
			cout<<1;
		}
	}
	return 0;
}
