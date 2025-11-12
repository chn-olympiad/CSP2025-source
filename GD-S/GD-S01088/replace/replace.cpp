#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s[200005],t[200005],a,b;int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
	}
	while(q--){
		cin>>a>>b;
		int sum=0;
		for(int i=1;i<=n;i++){
			int za=a.find(s[i]),zb=b.find(t[i]);
			//cout<<i<<" : "<<za<<" "<<zb<<"\n"; 
			if(za==zb&&a.substr(0,za)==b.substr(0,zb)&&a.substr(za+s[i].size())==b.substr(zb+t[i].size())){
				//cout<<a.substr(0,za)<<" "<<b.substr(0,zb)<<" "<<a.substr(za+s[i].size())<<" "<<b.substr(zb+t[i].size())<<"\n";
				sum++;
			}
		}
		cout<<sum<<"\n";
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
*/
