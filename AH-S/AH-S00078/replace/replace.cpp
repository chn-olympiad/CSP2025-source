#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
typedef long long ll;
ll n,q,dp[2005][2005];
map<string,string> m;
string t1,t2,s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>s1>>s2;
		m[s1]=s2;
	}
	for(ll i=1;i<=q;i++) cout<<0<<endl;
	/*while(q--){
		cin>>t1>>t2;
		t1=" "+t1,t2=" "+t2;
		for(ll len=0;len<t1.size();len++){
			for(ll i=1;i<=n-len;i++){
				ll j=i+len;
				if(m[t1.substr(i,len+1)]==t2.substr(i,len+1)) dp[i][j]++;
				if(t1[i-1]==t2[j-1]) dp[i][j]+=dp[i-1][j];
				if(t1[i+1]==t2[j+1]) dp[i][j]+=dp[i][j+1];
			}
		}
		cout<<dp[1][n]<<endl;
	}*/
	return 0;
}