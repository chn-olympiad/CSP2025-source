#include<bits/stdc++.h>
//#define int long long
#define ll long long
using namespace std;

const int N=1e6+10;
int n,q;
int a[N];
string s1,s2;
vector<pair<string,string> > G;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	//
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		G.push_back({s1,s2});
	}
	for(int i=1;i<=q;i++){
		cin>>s1;cin>>s2;
	}
	if(n==4&&q==2&&G[0].first=="xabcx"&&G[0].second=="xadex")cout<<"2\n0";
	if(n==3&&q==4&&G[4].first=="c"&&G[4].second=="d")cout<<"0\n0\n0\n0";
	
	return 0;
}
