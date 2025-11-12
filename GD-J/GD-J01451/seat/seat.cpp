#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
const int N=2e6+10,inf=0x3f3f3f3f,mod=1e9+7;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef long long ll;
/*
09:13
Task2 done.
*/
int n,m,a[N],bro,pos;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m>>bro; a[1]=bro;
	for(int i=2;i<=n*m;i++) cin>>a[i];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++) 
		if(bro==a[i]) pos=n*m-i+1;
		
	int px=(pos-1)/n+1;
	int py=px&1?(pos-1)%n+1:n-(pos-1)%n;
	cout<<px<<" "<<py;
	return 0;
}

