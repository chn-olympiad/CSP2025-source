#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct stu{
	int id,x,y,z;
}a[N];
int t,idx,n,o,mx,c1,c2,c3,ans,anss[10];
void dfs(int step){
	if(step == n + 1){
		mx = max(mx,ans);
		return;
	}
	if(c1 < o){
		c1 ++,ans += a[step].x;
		dfs(step + 1);
		c1 --,ans -= a[step].x;
	}
	if(c2 < o){
		c2 ++,ans += a[step].y;
		dfs(step + 1);
		c2 --,ans -= a[step].y;
	}
	if(c3 < o){
		c3 ++,ans += a[step].z;
		dfs(step + 1);
		c3 --,ans -= a[step].z;
	}
}
bool cmp(stu A,stu B){
	return A.x > B.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t --){
		cin >> n;
		o = n / 2,c1 = c2 = c3 = ans = mx = 0;
		bool flag = 0;
		for(int i = 1 ; i <= n ; i ++){
			cin >> a[i].x >> a[i].y >> a[i].z,a[i].id = i;
			if(a[i].y != 0 || a[i].z != 0) flag = 1;
		}
		if(!flag){
			sort(a + 1,a + n + 1,cmp);
			for(int i = 1 ; i <= o ; i ++)
				mx += a[i].x;
		}
		else dfs(1);
		anss[++ idx] = mx;
	}
	for(int i = 1 ; i <= idx ; i ++) cout << anss[i] << '\n';
	return 0;
}
