#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+5;
int n,m,a[maxn],x,pos;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
		if(a[i]==x) pos=i;
	int l=(n*m-pos+n)/n;
	cout<<l<<' ';
	if(l&1) cout<<((n*m-pos)%n+1);
	else cout<<(n-((n*m-pos)%n));
}
//信心赛吗？有点意思 
