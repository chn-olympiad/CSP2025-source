#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int, int>
using namespace std;
const int N = 1e5 + 5;

struct node{
	int a, b, c;
};

void sol(){
	int n;	cin>>n;
	vector<node> a(n + 5);
	vector<int> b(n + 5);
	for(int i = 1;i <= n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c; 
	}
	int res = 0;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	for(int i = 1;i <= n;i++){
		if(a[i].a >= max(a[i].b, a[i].c)){
			res += a[i].a, cnt1++, b[i] = 1;
		}
		else if(a[i].b >= max(a[i].a, a[i].c)){
			res += a[i].b, cnt2++, b[i] = 2;
		}
		else{
			res += a[i].c, cnt3++, b[i] = 3;
		}
	}
	vector<int> ans;
	for(int i = 1;i <= n;i++){
		if(cnt1 > n/2 && b[i] == 1)	ans.pb(a[i].a - max(a[i].b, a[i].c));
		if(cnt2 > n/2 && b[i] == 2)	ans.pb(a[i].b - max(a[i].a, a[i].c));
		if(cnt3 > n/2 && b[i] == 3)	ans.pb(a[i].c - max(a[i].a, a[i].b));
	}
	sort(ans.begin(), ans.end());
	int i = 0;
	while(cnt1 > n/2)	res -= ans[i++], cnt1--;
	while(cnt2 > n/2)	res -= ans[i++], cnt2--;
	while(cnt3 > n/2)	res -= ans[i++], cnt3--;
	cout<<res<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;	cin>>t;
	while(t--)	sol();
	return 0;
}
