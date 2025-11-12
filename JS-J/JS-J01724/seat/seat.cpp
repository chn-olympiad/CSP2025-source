#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod1 998244353
int n,m,a,x,i=1;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//input here
	cin>>n>>m>>a;
	while(cin>>x) if(x>a) i++;
	//main body here
	//output here
	cout<<(i-1)/n+1<<' '<<(((i-1)/n+1)%2==0?n-(i-1)%m:(i-1)%m+1);
}
