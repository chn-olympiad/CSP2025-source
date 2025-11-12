#include<bits/stdc++.h>
#define itn int
#define pb push_back
#define ll long long
#define endl '\n'
using namespace std;
const int MOD1=1e9+7;
const int MOD2=998244353;
const int N=1e6+5;
string s;
void Solve(){
	cin>>s;
	vector<int> v; 
	for(char i:s){
		if('0'<=i and i<='9')
			v.pb(i-'0');
	}
	sort(v.begin(),v.end());
	for(int i=v.size()-1;i>=0;i--)
		cout<<v[i];
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--)
		Solve();
	return 0;
}

