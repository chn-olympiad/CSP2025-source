#include<bits/stdc++.h>
using namespace std;
const int N = 10010,M = 1000010;
int n,m,k,cnt,ans;
int p[N];
struct node{
	int x,y,z;
}a[N];
int find(int x){
	if(p[x]!=x)p[x] = find(p[x]);
	return p[x];
}
bool cmp(node x,node y){
	return x.z<y.z;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++)p[i] = i;
	for(int i = 1;i <= m;i++){
		int x,y,z;
		cin >> x >> y >> z;
		a[++cnt] = {x,y,z};
	}
	if(k<=0){
		sort(a+1,a+1+cnt,cmp);
		for(int i = 1;i <= cnt;i++){
			int fx = find(a[i].x),fy = find(a[i].y);
			if(fx==fy)continue;
			p[fx] = fy;
			ans+=a[i].z;
		}
		cout << ans;
	}
	else{
		cout << 0;
	}
	return 0;
}

