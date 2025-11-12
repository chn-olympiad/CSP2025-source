#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 214514;
int _,n,m,k,t,a[N],b[N],ans,cnt;
string s;
bool vis[N],f;
bool cmp(int x,int y){
	return x>y;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int op=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==op){
			op=i;
			break;
		}
	}
	int jo=(op-1)/n+1;
	if(jo&1){
		cout<<jo<<" "<<op-(jo-1)*n;
	}
	else{
		cout<<jo<<" "<<n-(op-(jo-1)*n)+1;
	}
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	_=1;
	while(_--){
		solve();
	}
}
