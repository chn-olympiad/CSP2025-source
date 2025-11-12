#include<bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int,int>
#define ALL(x) x.begin(),x.end()
using namespace std;
const int MOD1=1e9+7,MOD2=998244353;
const int MOD=MOD1;
const int INF=1e18;
const int N=100005;
const int base=13;
int n,q;
pii w[N];
int gethash(string s){
	int res=0;
	for(int i=0;i<s.size();i++){
		res=(res*base%MOD+(s[i]-'a'))%MOD;
	}
	return res%MOD;
}
void solve_(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		string tmp1,tmp2;
		int pos1=0,pos2=0;
		for(int j=0;j<s1.size();j++){
			if(s1[j]!=s2[j]){
				pos1=j;
				break;
			}
		}
		for(int j=s1.size()-1;j>=0;j--){
			if(s1[j]!=s2[j]){
				pos2=j;
				break;
			}
		}
		for(int j=pos1;j<=pos2;j++){
			tmp1+=s1[j];
			tmp2+=s2[j];
		}
		w[i]={gethash(tmp1),gethash(tmp2)};
	}
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int testcase=1,multitest=0;
	if(multitest)cin>>testcase;
	while(testcase--){
		solve_();
	}
	return 0;
}
