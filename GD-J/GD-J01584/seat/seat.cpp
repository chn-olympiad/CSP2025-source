#include<bits/stdc++.h>
#define psb push_back
#define fi first
#define se second
#define endl '\n'
#define pii pair<int,int>
using namespace std;
const int N=105;
int n,m;
pii a[N];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].fi;
		a[i].se=i;
	}
	sort(a+1,a+1+n*m,greater<>());
	int rk=0;
	for(int i=1;i<=n*m;i++)if(a[i].se==1){rk=i;break;}
	int l=(rk-1)/n+1;
	if(l&1)cout<<l<<" "<<rk-(l-1)*n<<endl;
	else cout<<l<<" "<<n-(rk-(l-1)*n)+1<<endl;
	return 0;
}
