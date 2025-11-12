#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=20+5,mod=998244353;
int n,m,c[MAXN],id[MAXN];string S;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m>>S;S=" "+S;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)id[i]=i;
	int ans=0;
	do{
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++){
			if(S[i]=='0'||cnt>=c[id[i]])cnt++;
			else sum++;
		}
		ans+=sum>=m;
	}while(next_permutation(id+1,id+n+1));
	cout<<ans<<"\n";
}