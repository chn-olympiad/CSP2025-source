#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
struct node{
	int x,y,z,w,id;
}a[N];
int T,n,ans,d[4],dp[N];

int maxv(node x){
	int mx = max(x.x,max(x.y,x.z));
	return 2*mx-(x.x+x.y+x.z);
}

int iid(node x){
	if(max(x.x,max(x.y,x.z)) == x.x) return 1;
	else if(max(x.x,max(x.y,x.z)) == x.y) return 2;
	return 3;
}

bool cmp(node x,node y){
	return x.w > y.w;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			a[i].w = maxv(a[i]);
			a[i].id = iid(a[i]);
			cout << 1;
		}
		sort(a+1,a+n+1,cmp);
		for(int i = 1;i <= n;i++){
			if(d[a[i].id] < n/2){
				d[a[i].id]++;
				ans += max(a[i].x,max(a[i].y,a[i].z));
			}
			else{
				int num = a[i].id;
				if(num == 1) a[i].x = 0;
				else if(num == 2) a[i].y = 0;
				else a[i].z = 0;
				a[i].w = maxv(a[i]);
				a[i].id = iid(a[i]);
				if(!x.x&&!x.y&&!x.z) continue;
				i--;
			}
			cout << 2;
		}
		cout << ans << endl;
		ans = 0;
		for(int i = 1;i <= n;i++){
			a[i].id = a[i].w = a[i].x = a[i].y = a[i].z = 0;
		}
		for(int i = 1;i <= 3;i++){
			d[i] = 0;
		}
	}
	return 0;
}
