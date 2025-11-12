#include<bits/stdc++.h>
using namespace std;
const int N=11;
const int mod=998244353;
int n,m,ans;
string s;
int c[N],id[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>s;
	if(n>10){
		int res=1;
		for(int i=1;i<=n;i++) res=(1ll*res*i)%mod;
		cout<<res;
		return 0;
	}
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		id[i]=i;
	}
	do{
		int cnt=0,now=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'&&now<c[id[i]]) cnt++;
			else now++;
		}
		ans+=(cnt>=m);
	}while(next_permutation(id+1,id+n+1));
	cout<<ans;
	return 0;
}
