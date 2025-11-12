#include <bits/stdc++.h>
using namespace std;
#define ll long long
string t1,t2,s1[200010],s2[200010];
ll n,q,sa[200010],sb[200010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ll i=1,a,b;i<=n;i++){
		cin>>s1[i]>>s2[i];
		for(ll j=0;j<s1[i].size();j++){
			if(s1[i][j]=='b') sa[i]=j;
			if(s2[i][j]=='b') sb[i]=j;
		}
	}
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		cout<<"1\n";
		
	}
	return 0;
}
