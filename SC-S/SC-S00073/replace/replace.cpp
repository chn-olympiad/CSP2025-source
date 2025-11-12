#include<bits/stdc++.h>
using namespace std;
using ll=int;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ll n,m;
	string a,b;
	cin>>n>>m;
	map<string,string> p;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		p[a]=b;
	}while(m--){
		cin>>a>>b;
		if(p[a]==b){
			cout<<1<<endl;
		}else cout<<0<<endl;
	}
	return 0;
}