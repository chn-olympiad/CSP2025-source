#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

int n;
int a[100010][5];
int d[5];

struct edge{
	int maxx, x, id;
}s[100010];

bool cmp(edge x, edge y){
	return x.x>y.x;
}

int main(){
	
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while(T--){
		ll ans=0;
		d[1]=d[2]=d[3]=0;
		cin >> n;
		for(int i=1; i<=n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			int maxx=max(a[i][1], max(a[i][2], a[i][3]));
			int minn=min(a[i][1], min(a[i][2], a[i][3]));
			s[i].maxx=maxx;
			s[i].x=maxx-(a[i][1]+a[i][2]+a[i][3]-maxx-minn);
			s[i].id=i;
		}
		sort(s+1, s+n+1, cmp);
		for(int i=1; i<=n; i++){
			int x=0, y=0, id=s[i].id;
			for(int j=1; j<=3; j++){
				if(a[id][j]==s[i].maxx && (d[j]<d[x] || x==0)){
					x=j;
				}
			}
			if(d[x]>=n/2){
				for(int j=1; j<=3; j++){
					if(a[id][j]==-(s[i].x-s[i].maxx) && (d[j]<d[y] || y==0)){
						y=j;
					}
				}
				d[y]++;
				ans+=a[id][y];
			}else{
				d[x]++;
				ans+=a[id][x];
			}
		}	
		cout << ans << '\n';
	} 
	
	return 0;
} 
