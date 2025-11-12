#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e6 + 7;
int n, q, i, j, ta, tb;
string a, b;
int mp[N+N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++){
		cin>>a>>b;
		for(j=0;j<a.size();j++)if(a[j]=='b')ta=j;
		for(j=0;j<b.size();j++)if(b[j]=='b')tb=j;
		++mp[N+ta-tb];
	}
	while(q--){
		cin>>a>>b;
		for(j=0;j<a.size();j++)if(a[j]=='b')ta=j;
		for(j=0;j<b.size();j++)if(b[j]=='b')tb=j;
		cout<<mp[N+ta-tb]<<"\n";
	}
	return 0;
}

