#include <bits/stdc++.h>
#define ll long long
const int N = 1e6+10;
using namespace std;
int t,n,cnt[4];
ll ans = 0;
struct T{
	int id,val;
	bool operator < (T b){
		return val < b.val;
	}
}a[N][4];
struct T2{
	int id,val;
	friend bool operator <(T2 a,T2 b){
		return a.val > b.val;
	}
};
priority_queue <T2> q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
//		cout << "n "<<n << '\n';
		cnt[1] = cnt[2] = cnt[3] = 0;
		ans = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++){
				cin >> a[i][j].val,a[i][j].id = j;
			}
			sort(a[i]+1,a[i]+4);
		}
		for(int i = 1;i <= n;i++)
			ans = ans+a[i][3].val,q.push({a[i][3].id,a[i][3].val-a[i][2].val}),cnt[a[i][3].id]++;
		int maxn = 0,tmpid = 0;
		for(int i = 1;i <= 3;i++)
			if(maxn < cnt[i])
				maxn = cnt[i],tmpid = i;
		while(maxn > n/2){
//			cout <<"maxn "<< maxn << '\n';
			int tmp1 = q.top().val,tmp2 = q.top().id;
//			cout << tmpid << ' ' << tmp2<<' ' << q.size() << '\n';
			if(tmp2 == tmpid)
				maxn--,ans -= tmp1;
			q.pop();
		}
		while(q.size())
			q.pop();
		cout << ans << '\n';
	}
	return 0;
}

