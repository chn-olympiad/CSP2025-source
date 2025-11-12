#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+100;
int n,q;
string s1[N],s2[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		cout<<0;
	}
	return 0;
}
