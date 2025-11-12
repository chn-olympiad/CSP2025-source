#include<bits/stdc++.h>
using namespace std;
const int N=510;
const long long mod=998244353;
int id[N],c[N];
int main() {
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;cin>>n>>m;
	string s;cin>>s;s=' '+s;
	for(int i=1;i<=n;i++) cin>>c[i],id[i]=i;
	long long ans=0;
	do {
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++) {
			int x=id[i];
			if(cnt>=c[x]) {
				cnt++;continue;
			}
			if(s[i]=='1') sum++;
			else cnt++;
		}
		ans+=(sum>=m);
	}while(next_permutation(id+1,id+n+1));
	cout<<ans<<"\n";
	return 0;
}
