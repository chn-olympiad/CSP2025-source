#include<bits/stdc++.h>
#define eps 1e-6
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
#define fi first
#define se second
#define MOD 998244353
#define MAXN 505
int n,m,c[MAXN],p[MAXN],ans;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s,s=' '+s;
	for(int i=1;i<=n;i++)cin>>c[i],p[i]=i;
	do{
		int ref=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(ref>=c[p[i]])ref++;
			else if(s[i]=='1')cnt++;
			else ref++;
		}
		ans+=cnt>=m;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;

	return 0;
}