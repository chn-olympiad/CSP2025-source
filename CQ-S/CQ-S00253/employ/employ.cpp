#include<bits/stdc++.h>
using namespace std;
#define all(a) a.begin(),a.end()
#define fr first
#define sc second
#define pq priority_queue
#define gr greater
#define mkp make_pair
using ll=long long;
using db=double;
using pii=pair<int,int>;

int n,m,a[505],b[505];
string s;

void solve(){
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	int ans=0;
	for(int i=1;i<=n;i++) b[i]=i;
	do{
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(cnt>=a[b[i]]||s[i]=='0') cnt++;
		if(n-cnt>=m) ans++;
	}while(next_permutation(b+1,b+n+1));
	
	cout<<ans<<'\n';
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T=1;
//	cin>>T;
    while(T--) solve();
    return 0;
}
