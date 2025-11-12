#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+13;

int a[maxn][4];
int d1[maxn],d2[maxn],d3[maxn];
bool vis[maxn];

bool cmp(int a, int b){
	return a > b;
}

int findmaxn(int x[]){
	int maxval=-1,t;
	for(int i=1;i<=3;i++){
		if(x[i] > maxval){
			maxval = x[i];
			t = i;
		}
	}
	return t;
}


int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;
	while(T--){
		memset(a,0,sizeof(a));
		memset(d1,0,sizeof(d1));
		memset(d2,0,sizeof(d2));
		memset(d3,0,sizeof(d3));
		memset(vis, 0, sizeof(vis));
		
		bool flag2=0,flag3=0;
		int n;
		cin >> n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin >> a[i][j];
				//if(j==1)	d1[i] = a[i][j];
				//if(j==2)	d2[i] = a[i][j];
				//if(j==3)	d3[i] = a[i][j];
				
			}
		}
		
		int limi = n >> 1;
		int ans=0,cnt1=0, cnt2=0, cnt3=0;
		//sort(d1+1, d1+1+n, cmp);
		//sort(d2+1, d2+1+n, cmp);
		//sort(d3+1, d3+1+n, cmp);
		
		if(n==2){
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(j!=i){
						ans = max(ans, a[1][i]+a[2][j]);
					}
				}
			}
			cout << ans << endl;
			continue;
		}
		
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				int t = findmaxn(a[i]);
				ans += a[i][t];
				vis[i] = 1;
			}
		}
		
		cout << ans << endl;
		
	}
	
	return 0;
	
} 
