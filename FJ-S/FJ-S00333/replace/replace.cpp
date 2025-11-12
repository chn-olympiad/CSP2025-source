#include<bits/stdc++.h>
using namespace std;
int n,q;
pair<string,string>s[200005];
string x,y;
string change(string a,string b,string c){
	int k=c.find(a);
	return c.substr(0,k)+b+c.substr(k+b.size(),c.size()-b.size()-k);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].first>>s[i].second;
	}
	while(q--){
		int ans=0;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			if(x.find(s[i].first)==y.find(s[i].second)&&y.find(s[i].second)!=18446744073709551615&&change(s[i].first,s[i].second,x)==y){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

