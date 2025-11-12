#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+5;
int n,a[N][3],t,ct[3],ans;
struct node{
	int id,a,b;
}x[N];
bool cmp(node x,node y){
	return a[x.id][x.a]-a[x.id][x.b]>a[y.id][y.a]-a[y.id][y.b];
}
void work(){
	ct[0] = ct[1] = ct[2] = 0;
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		t = max(a[i][0],max(a[i][1],a[i][2]));
		x[i].id = i;
		if(a[i][0]==t){
			x[i].a = 0;
			if(a[i][1]>a[i][2])x[i].b = 1;
			else x[i].b = 2;
		}
		if(a[i][1]==t){
			x[i].a = 1;
			if(a[i][0]>a[i][2])x[i].b = 0;
			else x[i].b = 2;
		}
		if(a[i][2]==t){
			x[i].a = 2;
			if(a[i][0]>a[i][1])x[i].b = 0;
			else x[i].b = 1;
		}
	}
	sort(x+1,x+n+1,cmp);
	ans = 0;
	for(int i = 1;i<=n;i++){
		if(ct[x[i].a]<n/2){
			ct[x[i].a]++;
			ans+=a[x[i].id][x[i].a];
		}
		else{
			ct[x[i].b]++;
			ans+=a[x[i].id][x[i].b];
		}
	}
	cout << ans << "\n";
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)work();
	return 0;
}
