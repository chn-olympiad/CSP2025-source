#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
long long n,q;
pair<string,string> s[MAXN];
pair<string,string> t[MAXN];
long long ans[MAXN];
string x="",y="",z="";

int main(){
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].first>>s[i].second;
	}
	for(int j=1;j<=q;j++){
		cin>>t[j].first>>t[j].second;
	}
	//特殊性质A：
	
	//特殊性质B:
	
	
	for(int i=1;i<=q;i++){
		cout<<ans[i];
	}
	return 0;
}
