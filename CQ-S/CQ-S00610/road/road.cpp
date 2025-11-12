#include<bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

struct str{
	int x,y,z;
}arr[1000005],brr[1000005];

bool cmp(str a,str b){
	return a.z < b.z;
}

int n,m,k,f[1000005],v[15][10005],vis[1000005],x,ans = 0x7fffffff,cnt,now,num;

int get_f(int a){
	if(f[a] == 0){
		return a;
	}
	f[a] = get_f(f[a]);
	return f[a];
}

void kruskal(){
	sort(arr + 1,arr + 1 + m,cmp);
	for(int i=1;i<=m;i++){
//		cout << num <<endl;
		int fx = get_f(arr[i].x),fy = get_f(arr[i].y);
		if(fx != fy){
			f[fy] = fx;
			num++;
			arr[num] = arr[i];
			if(num == n - 1){
//				cout << num <<endl;
				return;
			}
		}
	}
}

int kruskal2(int a){
	int ans = num = 0;
	sort(brr + 1,brr + 1 + cnt,cmp);
	for(int i=1;i<=m;i++){
		int fx = get_f(arr[i].x),fy = get_f(arr[i].y);
		if(fx != fy){
			f[fy] = fx;
			ans += arr[i].z;
			num++;
			arr[num] = arr[i];
			if(num == a - 1){
				return ans;
			}
		}
	}
}

signed main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cin >> arr[i].x >> arr[i].y >> arr[i].z;
	}
	kruskal();
//	cout << num <<endl;
//	for(int i=1;i<=num;i++){
//		cout << arr[i].x <<" "<< arr[i].y <<endl;
//	}
	for(int i=1;i<=k;i++){
		cin >> v[i][0];
		for(int j=1;j<=n;j++){
			cin >> v[i][j];
		}
	}
	for(int i=1;i<(1<<k);i++){
		now = num = 0;
		for(int j=1;j<n;j++){
			brr[j] = arr[j];
		}
		cnt = n - 1;
		for(int j=1;j<=k;j++){
			if((i & (1 << (j - 1))) != 0){
				now += v[j][0];
				num++;
				for(int k=1;k<=n;k++){
					cnt++;
					brr[cnt] = {n + j,k,v[j][k]};
				}
			}
		}
		for(int i=1;i<=n+k;i++){
			f[i] = 0;
		}
		ans = min(ans,kruskal2(n + num) + now);
	}
	cout << ans;
	
	return 0;
}
