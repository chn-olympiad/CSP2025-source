#include<iostream>
#include<vector>
using namespace std;
const int MAXN = 1e4 + 5;
int n,m,k;
struct rd{
	int v,w;
};
vector <rd> vt[MAXN];
int a[20][MAXN],b[MAXN],c[MAXN],sss[MAXN],d[MAXN];
bool vis[MAXN];
long long ans = 0;
int cnt = 0; 
int main(){
	//freopen("road1.in","r",stdin);
	//freopen("road1.out","w",stdout);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= n;i++) b[i] = -1;
	for(int i = 1;i <= m;i++){
		int uu,vv,ww;
		cin >> uu >> vv >> ww;
		vt[uu].push_back({vv,ww});
		vt[vv].push_back({uu,ww});
		if(b[uu] == -1) b[uu] = ww;
		b[uu] = min(b[uu],ww);
		if(b[vv] == -1) b[vv] = ww;
		b[vv] = min(b[vv],ww);
	} 
	for(int i = 1;i <= k;i++){
		for(int j = 0;j <= n;j++){
			cin >> a[i][j];
			if(j !=0 && i == 1) c[j] = a[i][j];
			c[j] = min(a[i][j],c[j]);
		}
	}
	for(int j = 1;j <= n;j++){
		if(a[1][j] == 0) vis[j] = 1;
		if(c[j] == a[1][j] && c[j] < b[j]) vis[j] = 1,cnt++,sss[cnt] = j,ans+=c[j];
	}int ard = 1;
	for(int i = ard;i <= cnt;i++){
		for(int j = 1;j <= vt[sss[i]].size();j++){
			int uu = sss[i],vv = vt[sss[i]][j].v,ww = vt[sss[i]][j].w;
			if(ww == b[vv] && b[vv] < c[vv]){
				vis[vv] = 1,sss[++cnt] = vv;
				ans+=ww;
			}
		}	
	}
	for(int i = 2;i <= k;i++){
		bool flag = 0;
		int jsq = 0;
		for(int j = 1;j <= n;j++){
			if(a[i][j] == 0){
				if(!vis[a[i][j]]){
					d[++jsq] = a[i][j];
				}else{
					flag = 1;
				}
			}
		} 
		if(flag){
			for(int j = 1;j <= n;j++){
				if(a[2][j] == 0) vis[j] = 1;
				if(c[j] == a[2][j] && c[j] < b[j] && !vis[j]) vis[j] = 1,cnt++,sss[cnt] = j,ans+=c[j];
			}for(int ii = ard;ii <= cnt;ii++){
				for(int j = 1;j <= vt[sss[ii]].size();j++){
					int uu = sss[ii],vv = vt[sss[ii]][j].v,ww = vt[sss[ii]][j].w;
					if(ww == b[vv] && b[vv] < c[vv]){
						vis[vv] = 1,sss[++cnt] = vv,ans += ww;
					}
				}	
			}
		}
	}
	cout << ans << endl;
	return 0;
}
