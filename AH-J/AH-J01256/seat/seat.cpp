#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[105];
ll g[15][15];
bool cmp(const ll &x,const ll &y){
	return x>y;
}
int main(){;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m,t;
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	int f=0;
	for(int i=1;i<=n*m;i++){
		g[x][y]=a[i];
		if(f==0) x++;
		else x--;
		if(x>n){
			y++;
			x=n;
			f=1;
		}else if(x<1){
			y++;
			x=1;
			f=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(g[i][j]==t){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	return 0;
}
