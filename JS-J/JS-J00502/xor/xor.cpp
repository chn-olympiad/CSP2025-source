#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=2e5+5;
int n,k;
int a[N];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	FOR(i,1,n) cin>>a[i];
	int cnt=0;
	FOR(i,1,n) if(a[i]==1) cnt++;
	if(k==0) cout<<n-cnt+(cnt/2);
	else if(k==1) cout<<cnt;
	return 0;
}
