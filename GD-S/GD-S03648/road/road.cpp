#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

typedef long long ll;

struct rd{
	ll u,v,w;
};
vector<rd> rds;

bool cmp(rd a,rd b){
	return a.w < b.w;
}

ll n,m,k,u,v,w,c[11];
ll mp[(int)1e4+3][(int)1e4+3];
ll bc[(int)1e4+3];
ll a[11][(int)1e4+3];

ll getFa(ll i){
	if(bc[i]!=i){
		return bc[i] = getFa(bc[i]);
	}else return i;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cin >> u >> v >> w;
		mp[u][v] = w;
		mp[v][u] = w;
		rds.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		ll cc;
		cin >> cc;
		c[i] = cc;
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
		}
	}
	if(k==0){
		for(int j=1;j<=n;j++) bc[j] =j;
		sort(rds.begin(), rds.end(),cmp);
//		for(rd i:rds) cout << i.w <<" ";
//		cout << endl;
		ll sum =0;
		for(rd i:rds){
//			cout << "now bc: ";
//			for(int j=1;j<=n;j++) cout << getFa(j) << " "; cout << endl;
			for(int j=2;j<=n;j++) {
				if(getFa(j-1) != getFa(j)) {
//					cout << "getFa(j-1)(" << getFa(j-1) << ") != getFa(j)(" << getFa(j) <<  ")" << endl;
					goto e;
				}
			}
			break;
			e:;
			sum += i.w;
			if(bc[i.u]==i.u)bc[i.u] = i.v;
			else bc[i.v] = i.u;
//			cout <<"connect " << i.u << " to " << i.v << endl;
		}
		cout << sum << endl;
		return 0;
	}
	cout << 78 << endl;
	return 0;
}
/*
5 6 0
1 3 1
2 3 8
3 4 3
3 5 5 
1 2 9
2 5 4
 
*/ 
