#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 20;
int t,n;
int a[N][5],b[N][3],d[5];
vector<int> v[5];
int cnt = 0;
int tmp[N];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		for(int i = 1;i <= cnt;i++) tmp[i] = 0;
		for(int i = 1;i <= 3;i++) v[i].clear();
		cnt = 0;
		for(int i = 1;i <= n;i++){
			b[i][1] = 0;
			b[i][2] = 0;
		}
		scanf("%d",&n);
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++) scanf("%d",&a[i][j]);
			
		}
		for(int i = 1;i <= n;i++){
			int mx = -1,mn = -1;
			int mx_id,mn_id;
			for(int j = 1;j <= 3;j++){
				if(a[i][j] > mx){
					mn = mx;
					mx = a[i][j];
					
					mn_id = mx_id;
					mx_id = j;
				}else if(a[i][j] > mn){
					mn = a[i][j];
					mn_id = j;
				}
			}
			b[i][1] = mx_id,b[i][2] = mn_id;
			//cout << b[i][1] << " " << b[i][2] << '\n';
		}
		for(int i = 1;i <= 3;i++) d[i] = 0;
		int ans = 0;
		int p = 0,q = 0;
		for(int i = 1;i <= n;i++){
			if(a[i][1] >= a[i][2]) p++;
			else q++;
		}
		
		for(int i = 1;i <= n;i++){
			d[b[i][1]]++;
			v[b[i][1]].push_back(i);
			ans += a[i][b[i][1]];
			//ans += max(a[i][1],a[i][2]);
		}
		
		for(int i = 1;i <= 3;i++){
			
			if(d[i] > n/2){
				int len = v[i].size();
				for(int j = 0;j < len;j++){
					int mp = v[i][j];
					tmp[++cnt] = a[mp][b[mp][2]] - a[mp][b[mp][1]];
					//tmp[++cnt] = min(a[v[i][j]][1],a[v[i][j]][2]) - max(a[v[i][j]][1],a[v[i][j]][2]);
					//cout << v[i][j] << " " << b[v[i][j]][2] << " " << b[v[i][j]][1] << '\n';
					//cout << tmp[cnt] << '\n';
				}
				sort(tmp + 1,tmp + 1 + cnt,cmp);
				int cnt2 = d[i] - n/2;
				for(int j = 1;j <= cnt2;j++){
					
					ans += tmp[j];
				}
				
			}
		}
		cout << ans << '\n';
		
 	}
	return 0;
}
