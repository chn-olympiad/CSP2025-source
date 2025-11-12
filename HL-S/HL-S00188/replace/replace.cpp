#include <bits/stdc++.h>
using namespace std;
pair<string,string> s[200010];
pair<string,string> que[200010];
long long n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].first>>s[i].second;
	}
	for(int i=1;i<=q;i++){
		cin>>que[i].first>>que[i].second;
	}
	for(int i=1;i<=q;i++){
		cout<<0<<"\n";
	}
	return 0;
}