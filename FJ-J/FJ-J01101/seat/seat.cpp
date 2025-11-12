#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

int n,m,s;
int a[105];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("seat.in","r",stdin); freopen("seat.out","w",stdout);
	cin>>n>>m; s=n*m;
	for(int i=1;i<=s;i++) cin>>a[i];
	int rs=a[1];
	sort(a+1,a+1+s,greater<int>());
	int p=0;
	for(int i=1;i<=s;i++) if(a[i]==rs) p=i;
	int c=(p-1)/n+1,r=(p-1)%n+1;
	if(c%2) cout<<c<<" "<<r<<endl;
	else cout<<c<<" "<<n-r+1<<endl;
	return 0;
}

//==============================T2==============================//
// xiang jin CSP-J/S2025 mi huo xing wei da shang
// freopen("number.in","r",stdin)
// freopen("number.in","w",stdin)
// freopen("number.out","r",stdout)
// freopen("number4.in","r",stdin)
// int mian
// itn nit
//==============================================================//
// my luogu uid is 693282 please guan zhu me
// I want to AFO because of whk and PE
// but I want to get a good score in CSP-J/S2025
// maybe I should AFO if I get <1= on CSP-J or get <2= on CSP-S
//==============================================================//
// gu fen: 100+100+30+64=294
//==============================================================//
