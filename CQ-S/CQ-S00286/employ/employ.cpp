#include<bits/stdc++.h>
#define endl '\n'
#define debug(x) cerr<<#x<<':'<<x<<endl
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int n,m;
string s;
int c[505],p[505],ans;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) cin>>c[i],p[i]=i;
	do{
		int sum=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||i-1-sum>=c[p[i]]) continue;
			else sum++;
		}
		if(sum>=m) ans++;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}

