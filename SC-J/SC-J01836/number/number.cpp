#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+5;
long long a[N],b[N];
long long pre[N],dp[N],vis[N];
long long n,m,k,t,sum=0,ans=0,mx,mn;
struct al{
	long long x,y,sum=0;
}c[N];
vector<long long>v;
string s,s1,s2;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0); 
	
	cin>>s;
	multiset<int>st;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			st.insert((s[i]-'0')*-1);
		}
	}
	for(auto x:st){
		cout<<x*-1;
	}
	return 0;
}
/*
5

5
--
290es1q0

92100
--
0u050hz08t2ibm70y4exp04u6m44838cont753674e569zh6hpkxr9tyd0l1odacalb5u0a835e7631x9581dy8pnui496e7t0bx


99998888887777766666655555544444433332111000000000
--


*/