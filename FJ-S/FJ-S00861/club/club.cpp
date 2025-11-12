#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+10;
ll a[N][5];
struct node{
	ll x;
	ll id;
	ll to;
}x[5][N];
ll n,vis[N],tot[5],t[5],ans,T;
vector < node > v[3][N];
inline ll read(){
	ll x=0,f=1;
	char ch = getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f = -1;
		ch = getchar();
	}
	while('0'<=ch&&ch<='9'){
		x = x*10+ch-'0';
		ch = getchar();
	}
	return x*f;
}
bool cmp(node xx,node yy){
	return xx.x>yy.x;
}
void add(ll xx,ll mx){
	t[mx]++;
	tot[mx]++;
	for(ll i=1;i<=3;i++){
		if(i==mx) continue;
		x[mx][++tot[mx]].x = -a[xx][mx]+a[xx][i];
		x[mx][tot[mx]].id = xx;
		x[mx][tot[mx]].to = i;
	}
	return ;
}
void solve(ll mx){
	sort(x[mx]+1,x[mx]+tot[mx]+1,cmp); 
	for(ll i=1;i<=tot[mx];i++){
		if(t[mx]<=n/2) break;
		if(vis[x[mx][i].id]==0&&t[x[mx][i].to]+1<=n/2){
			vis[x[mx][i].id] = 1;
			ans = ans+x[mx][i].x;
			t[x[mx][i].to]++;
			t[mx]--;
		}
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		n = read();
		t[1] = t[2] = t[3] = 0;
		tot[1] = tot[2] = tot[3] = 0;
		ans = 0;
		for(ll j=1;j<=3;j++){
			for(ll i=1;i<=tot[j];i++){
				x[j][i].x = 0;
				x[j][i].id = 0;
				x[j][i].to = 0;
			}	
		}
		for(ll i=1;i<=n;i++) vis[i] = 0;
		for(ll i=1;i<=n;i++){
			a[i][1] = read();
			a[i][2] = read();
			a[i][3] = read();
			if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][1]){
		//		cout<<a[i][1]<<endl;
				ans += a[i][1];
				add(i,1);
			}
			else if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][2]){
				ans += a[i][2];
				add(i,2);
			}
			else if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][3]){
				ans += a[i][3];
				add(i,3);
			}
		}
	//	cout<<ans<<endl;
	//	cout<<t[1]<<" "<<t[2]<<" "<<t[3]<<endl;
		if(t[1]>n/2){
			solve(1);
		}
		if(t[2]>n/2){
			solve(2);
		}
		if(t[3]>n/2){
			solve(3);
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
4
4 2 1
3 2 4
5 3 4
3 5 1
1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
