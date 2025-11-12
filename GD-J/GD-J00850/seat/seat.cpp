#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef double dou;

const int N = 1e2 + 10;

ll n,m,numb,score;
ll a[N];
ll mp[N][N];

bool cmp(ll x,ll y){
	return x>y;
}

void solve(){
	cin >> n >> m >> score;
	a[1] = score;
	for(int i=2;i<=n*m;i++)
		cin >> a[i];
	sort(a+1,a+n*m+1,cmp);
	ll i=1;
	for(int j=1;j<=n;j++){
		for(int k=1;k<=m;k++){
			if(j%2==1) mp[j][k] = a[i++];
			else mp[j][n-k+1] = a[i++];
		}
	}
	bool flag = 0;
	for(int j=1;j<=n;j++){
		for(int k=1;k<=m;k++){
			if(mp[j][k]==score){
				cout << j << ' ' << k;
				flag = 1;
				break;
			}
		}
		if(flag) break;
	}
}

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	solve();
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
