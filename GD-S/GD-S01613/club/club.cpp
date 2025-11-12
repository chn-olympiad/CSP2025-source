#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const int maxn = 1e5+10;
int n,cnt,T;
int t1,t2,t3;
ll a[maxn][4];
ll dp[205][150][150];
ll ans; 
vector<ll> v;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--){
		ans = 0;
		t1 = t2 = t3 = 0;
		cin >> n;
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		v.clear();
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				cin >>a[i][j];
				if(a[i][j] != 0 &&j == 1) {
					t1++;
				}
				if(a[i][j] != 0 &&j == 2){
					t2++;
				}
				if(a[i][j] != 0 &&j == 3){
					t3++;
				}
			}
		
		}
			if(t1 == 0 && t2 == 0){
			
				for(int i = 1; i <= n; i++){
					v.push_back(a[i][3]);
				}
				sort(v.begin(),v.end());
				reverse(v.begin(),v.end());
				for(int i = 0; i < n/2; i++){
					ans+=v[i];
				}
				v.clear();
				cout << ans <<endl;
			}else if(t1 == 0 &&t3 == 0){
		
				for(int i = 1; i <= n; i++){
					v.push_back(a[i][2]);
				}
				sort(v.begin(),v.end());
				reverse(v.begin(),v.end());
				for(int i = 0; i < n/2; i++){
					ans+=v[i];
				}
				cout << ans <<endl;
			}else if(t2 == 0 &&t3 == 0){
			
				for(int i = 1; i <= n; i++){
					v.push_back(a[i][1]);
				}
				sort(v.begin(),v.end());
				reverse(v.begin(),v.end());
				for(int i = 0; i < n/2; i++){
					ans+=v[i];
				}
				cout << ans <<endl;
			}else{
			
			for(int i = 1; i <= n; i++){
				for(int j = 0; j <= min(i,n/2); j++){
					for(int k = 0; k <= min(i-j,n/2); k++){
						int t = i-j-k;
						if(j){
							dp[i][j][k] = max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
						}
						if(k){
							dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
						}
						if(t && t <= n/2){
							dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
						}
						ans = max(dp[i][j][k],ans);
					}
				}
			
			}
			cout << ans <<endl;
		}
	}
	return 0;
} 
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const int maxn = 1e5+10;
int n,cnt,T;
int vis[maxn];
ll a[maxn][3];
priority_queue<pii> p1,p2,p3;
struct node{
	int p;
	ll v;
	int idx;
}t[maxn];
bool cmp(node x,node y){
	return x.v > y.v;
}

ll s1,s2,s3;
int l1,l2,l3;
int main(){
	freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--){
		cin >> n;
		cnt = n*3;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				cin >> a[i][j];
				t[i].v = a[i][j];
				t[i].idx = i;
				t[i].p = j;
			}
		}
		sort(t+1,t+1+cnt,cmp);
		for(int i = 1; i <= cnt; i++){
		
			//cout << i.first <<" " << i.second<<endl;
	
			ll v = t[i].v;
			int p = t[i].p;
			int idx = t[i].idx; 
			if(vis[idx]) continue;
			if(p == 1){
				if(l1 < n/2){
					s1+=v;
					l1++;
					p1.push({-(a[idx][1]-a[idx][2]),idx});
					p2.push({-(a[idx][1]-a[idx][3]),idx});
				}else{
					ll m = a[idx][1],n = a[idx][2],o = a[idx][3];
					if(m-n >= n-o){
						if(-(p1.top().first) < m-n){
							p2.push(p1.top());
							s1-=a[p1.top().second][1];
							s1+=m;
							s2+=a[p1.top().second][1];
							p1.pop();
							p1.push({-(m-n),p});
						}else if(-(q2.top().first)){
								
						} 
					}else{
						if(-())
					}
				}
				
			}else if(p == 2){
				if(l2 < n/2){
					s2+=v;
					l2++;
					p1.push({-(a[idx][2]-a[idx][1]),idx});
					p3.push({-(a[idx][2]-a[idx][3]),idx});
				}
			}else if(p == 3){
				if(l3 < n/2){
					s3+=v;
					l3++;
					p2.push({-(a[p][3]-a[p][1]),idx});
					p3.push({-(a[p][3]-a[p][2]),idx});
				}
			}
		}
	}

	return 0;
} 
*/
