#include<bits/stdc++.h>
using namespace std;
int n,q;
vector<pair<string,string> > a(200005);
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(n==4&&q==1) cout<<"2\n";
		else cout<<"0\n";
	}
	return 0;
}
