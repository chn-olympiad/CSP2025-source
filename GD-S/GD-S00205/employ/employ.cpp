#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,P=998244353;
int n,m,c[N],cnt[N],id[N],ans;
string s;
inline int solve1(){
	do{
		int res=0,abd=0;
		for(int i=1;i<=n;i++){
			res+=(s[i-1]==49&&cnt[i]+abd<c[id[i]]);
			abd+=(s[i-1]==49&&cnt[i]+abd>=c[id[i]]);
		}ans+=(res>=m);ans%=P;
//	freopen
//	Final dance for CSP. Enjoy yourself please.
	}while(next_permutation(id+1,id+1+n));
	cout<<ans;
	return 0;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];id[i]=i;
	}
	for(int i=2;i<=n;i++)
		cnt[i]=cnt[i-1]+(s[i-2]==48);
	return solve1();
	return 0;
}
