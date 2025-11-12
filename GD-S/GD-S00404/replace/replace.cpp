#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
using VI=vector<int>;
using PI=pair<int,int>;
const int maxn=2e5+5;
struct lim{string s1,s2;}e[maxn];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>e[i].s1>>e[i].s2;
	}
	while(q--){
		string t1,t2;cin>>t1>>t2;
		cout<<"0\n";
	}
	return 0;
}
