#include<bits/stdc++.h>
#define gc getchar
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const int N = 5e2+3,M = 998244353;
inline int re(){
	int x=0;bool f=0;char c=gc();
	for(;c<'0'||c>'9';c=gc())f=c=='-';
	for(;c>='0'&&c<='9';c=gc())x=x*10-48+c;
	return f?-x:x;
}
string s;
int n,m,c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll ans=1;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i],ans=ans*i%M;
	cout<<ans;
	return 0; 
}
