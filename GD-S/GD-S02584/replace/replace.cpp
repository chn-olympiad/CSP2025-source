#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,q,jl[N];
ll cnt;
string s,ss,t,tt;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s>>ss;
		int cnt=0,cntt=0;
		for(int j=0;j<=s.size();j++){
			if(s[j]=='b') cnt=j;
			if(ss[j]=='b') cntt=j;
		}
		jl[i]=cntt-cnt;
	}
	for(int i=1;i<=q;i++){
		cin>>t>>tt;
		cnt=0;
		int jj,ll;
		for(int j=0;j<t.size();j++){
			if(t[j]=='b') jj=j;
			if(tt[j]=='b') ll=j;
		}
		for(int i=1;i<=n;i++){
			if(jl[i]==ll-jj) cnt++;
		}
		printf("%lld\n",cnt);
	}
	return 0;
}

