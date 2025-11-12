#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct qwq{
	int x,y,z;
}a[100005],s[3][100005];
bool cmp0(qwq p,qwq q){
	return p.x-max(p.y,p.z)<q.x-max(q.y,q.z);
}
bool cmp1(qwq p,qwq q){
	return p.y-max(p.x,p.z)<q.y-max(q.x,q.z);
}
bool cmp2(qwq p,qwq q){
	return p.z-max(p.y,p.x)<q.z-max(q.y,q.x);
}
int T,n,N,t[3],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> n;
		N = n>>1;
		t[0] = t[1] = t[2] = 0;
		ans = 0;
		for(int i = 0;i < n;i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			int k = max(a[i].x,max(a[i].y,a[i].z));
			ans += k;
			if(k == a[i].x){
				s[0][t[0]++] = a[i];
			}else if(k == a[i].y){
				s[1][t[1]++] = a[i];
			}else{
				s[2][t[2]++] = a[i];
			}
		}
		int j = 0;
		sort(s[0],s[0]+t[0],cmp0);
		while(t[0] > N){
			ans -= s[0][j].x-max(s[0][j].y,s[0][j].z);
			j++;
			t[0]--;
		}
		j = 0;
		sort(s[1],s[1]+t[1],cmp1);
		while(t[1] > N){
			ans -= s[1][j].y-max(s[1][j].x,s[1][j].z);
			j++;
			t[1]--;
		}
		j = 0;
		sort(s[2],s[2]+t[2],cmp2);
		while(t[2] > N){
			ans -= s[2][j].z-max(s[2][j].y,s[2][j].x);
			j++;
			t[2]--;
		}
		cout << ans << '\n';
	}
	return 0;
}
