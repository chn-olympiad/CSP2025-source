#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+34;

bool Mbe;
ll T;

struct node{
	ll x,y,z;
};

node a[N];
ll vis[4];// 记录每一组选了几个人 

struct node2{
	ll val,from; // 值，哪个人的选择 
	friend bool operator < (node2 a, node2 b){
		return a.val < b.val;
	}
};
vector<node2> s[4];


int get_gp(int x,int y,int z){
	if ((x >= y && y >= z) || (x >= z && z >= y)){	
		return 1;
	}
	if ((y >= x && x >= z) || (y >= z && z >= x)){
		return 2;
	}
	if ((z >= x && x >= y) || (z >= y && y >= x)){
		return 3;
	}
	return 0; 
}
/*
1
6
2 3 9
1 1 4
2 4 8
0 0 4
3 8 0
7 7 1

*/
void solve(){
	ll n=0,tot=0,gMax=-1, beyond_g=0;
	cin >> n;
	vis[1]=0,vis[2]=0,vis[3]=0;
	s[1].clear(), s[2].clear(),s[3].clear();
	
	gMax = (n >> 1);
	for (int i = 1; i<=n;i++){
		int x,y,z,maxx=-1;
		cin >> x>> y >> z;
		a[i]= {x,y,z};
		maxx = max({x,y,z});
		tot += maxx; // 先选每一组最大的 
		int gp = get_gp(x,y,z);
//		cout << "i : " << maxx << ' ' << gp << '\n'; 
		vis[gp]++;
		s[gp].push_back({maxx,i});
	}
//	cout <<"check:"<< vis[1] << ' ' << vis[2] << ' ' << vis[3] << '\n';
	if (vis[1] <= gMax && vis[2] <= gMax && vis[3] <= gMax){
		cout << tot << '\n';
		return;
	}

	
	if (vis[1] > gMax) beyond_g = 1;
	if (vis[2] > gMax) beyond_g = 2;
	if (vis[3] > gMax) beyond_g = 3;
	ll  beyond_num = vis[beyond_g]-gMax;
//	cout << "beyound_gp is: " << beyond_g << ' ' << beyond_num << '\n';
	for (int j = 1; j <= beyond_num;j++){
		ll minn = 1e18;
		int minpos=-1;
		for (int i =0; i < (ll)s[beyond_g].size();i++){
			node2 u = s[beyond_g][i];
			ll from = u.from;
			ll curval = u.val;
			if (curval==-1)continue;
			if (curval == a[from].x){
				if (curval-a[from].y <= curval-a[from].z){
					if (minn >= curval-a[from].y){
						minn = curval-a[from].y;
						minpos = i;
					}
				}
				else{
					if (minn >= curval-a[from].z){
						minn = curval-a[from].z;
						minpos = i;
					}
				}
				
//				cout << "ix: " << i << ' ' << curval << '\n';
			}
			if (curval == a[from].y){
					if (curval-a[from].x <= curval-a[from].z){
					if (minn >= curval-a[from].x){
						minn = curval-a[from].x;
						minpos = i;
					}
				}
				else{
					if (minn >= curval-a[from].z){
						minn = curval-a[from].z;
						minpos = i;
					}
				}
				
//				cout << "iy: " << i << ' ' << curval << '\n';
			}if (curval == a[from].z){
				if (curval-a[from].x <= curval-a[from].y){
					if (minn >= curval-a[from].x){
						minn = curval-a[from].x;
						minpos = i;
					}
				}
				else{
					if (minn >= curval-a[from].y){
						minn = curval-a[from].y;
						minpos = i;
					}
				}
				
//				cout << "iz: " << i << ' ' << minpos<< ' ' << curval << ' ' << from << ' ' << minn<<'\n';
			}

		}
//		cout << "mincheck: "  << ' ' << minn <<  ' ' << minpos << '\n';
		tot-=minn;
		if (minpos!=-1){
			
			s[beyond_g][minpos]={-1,-1};
//			cout << "done\n";
		}
	}
	cout << tot << '\n';

	
	
	
//	for (int i = 1; i <= 3;i++)
//	{
//		cout << "group: " << i << '\n';
//		for (auto u : s[i]){
//			cout << u.val << ' ' << u.from << '\n'; 
//		}
//	}
//	cout << tot << '\n'; 

	
}
bool Med;
int main(){
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout); 
//	freopen("C:\\Users\\Administrator\\Desktop\\题目\\club\\club5.in","r",stdin); 
//	freopen("out.txt","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	cerr << "Mem: " << double(&Mbe-&Med) / 1048576.0 << "MB\n";
	cin >> T;
	while (T--){
		solve();
	}

	return 0;
}

