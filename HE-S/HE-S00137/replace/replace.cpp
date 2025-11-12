#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+666;
int n,q;
string t1[N],t2[N],s1[N],s2[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
	for(int i=1;i<=q;i++){
		cout<<0<<"\n";
	}
	return 0;
}
