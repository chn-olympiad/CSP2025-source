#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Node{
	int val,id;
	friend bool operator < (Node a,Node b){
		return a.val > b.val;
	}
}a[500006][4];
int cnt[4],p[500006],tot,n,T;
void solve(){
	cnt[1] = cnt[2] = cnt[3] = 0;
	tot = 0;
	cin >> n;
	int ID = 0,ans = 0,Max = 0;
	for(int i = 1;i <= n; i++){
		for(int j = 1;j <= 3; j++){
			scanf("%lld",&a[i][j].val);
			a[i][j].id = j;
		} 
		sort(a[i]+1,a[i]+4);
		cnt[a[i][1].id]++;
		ans += a[i][1].val;
		cnt[a[i][1].id]++;
		if(cnt[a[i][1].id] > Max){
			Max = cnt[a[i][1].id];
			ID = a[i][1].id;
		}
		
	}
	if(Max > n/2){
		for(int i = 1;i <= n; i++)
			if(a[i][1].id == ID)
				p[++tot] = a[i][2].val-a[i][1].val;
		sort(p+1,p+1+tot,greater<int>());
		for(int i = 1;i <= tot-n/2; i++)
			ans += p[i];
	}
	cout << ans << endl;
}
main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--)
		solve();
	return 0;
}
