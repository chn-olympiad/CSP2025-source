#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>a;
string s;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	cin>>s;
	for(auto k:s){
		if(k<'0'||k>'9') continue;
		a.push_back(k-48);
	}
	sort(a.begin(),a.end(),cmp);
	for(auto k:a) cout<<k;
	return 0;
}
