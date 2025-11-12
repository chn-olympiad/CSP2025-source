#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;

struct node{
	int id;
	int a1,a2,a3;
}a[N];

struct og{
	int id,num;
};

bool cmp1(og x,og y){
	return x.num - max(a[x.id].a2,a[x.id].a3) > y.num - max(a[y.id].a2,a[y.id].a3);
}

bool cmp2(og x,og y){
	return x.num - max(a[x.id].a1,a[x.id].a3) > y.num - max(a[y.id].a1,a[y.id].a3);
}

bool cmp3(og x,og y){
	return x.num - max(a[x.id].a2,a[x.id].a1) > y.num - max(a[y.id].a2,a[y.id].a1);
}

vector<og> v1,v2,v3;
int n,ans;

void solve(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
		a[i].id = i;
		if(a[i].a1 >= a[i].a2 && a[i].a1 >= a[i].a3)v1.push_back({i,a[i].a1});
		else if(a[i].a2 >= a[i].a1 && a[i].a2 >= a[i].a3)v2.push_back({i,a[i].a2});
		else v3.push_back({i,a[i].a3});
	}
	sort(v1.begin(),v1.end(),cmp1);
	sort(v2.begin(),v2.end(),cmp2);
	sort(v3.begin(),v3.end(),cmp3);
	int l1 = v1.size(),l2 = v2.size(),l3 = v3.size();
	for(int i=0;i<l1;i++){
		if(i >= n/2){
			ans += max(a[v1[i].id].a2,a[v1[i].id].a3);
		}else{
			ans += v1[i].num;
		}
	}
	for(int i=0;i<l2;i++){
		if(i >= n/2){
			ans += max(a[v2[i].id].a1,a[v2[i].id].a3);
		}else{
			ans += v2[i].num;
		}
	}
	for(int i=0;i<l3;i++){
		if(i >= n/2){
			ans += max(a[v3[i].id].a2,a[v3[i].id].a1);
		}else{
			ans += v3[i].num;
		}
	}
	v1.clear();
	v2.clear();
	v3.clear();
	cout << ans << '\n';
	ans = 0;
	return;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T = 1;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}
