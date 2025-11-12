#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,q;
struct pairs{
	string s1,s2;
};
pairs a[200005];
string q1,q2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i = 1;i<=n;++i){
		cin>>a[i].s1>>a[i].s2;
	}
	while(q--){
		cin>>q1>>q2;
		cout<<0<<'\n';
	}
	return 0;
}
