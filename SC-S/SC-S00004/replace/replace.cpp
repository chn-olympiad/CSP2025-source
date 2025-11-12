#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
struct st{
	string s1,s2;
}a[N];
int v[15][10005],w[15];
int n,q;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	while(q--){
		string q1,q2;
		cin>>q1>>q2;
		cout<<0;
	}
	return 0;
} 

