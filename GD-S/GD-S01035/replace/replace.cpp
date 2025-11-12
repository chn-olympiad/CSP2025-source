#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
string s1,s2;
int n,m;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>s1>>s2;
	}
	for(int i=1;i<=m;++i){
		cin>>s1>>s1;
		cout<<min((int)s2.size(),(int)s1.size())<<endl;
	}
	return 0;
}
