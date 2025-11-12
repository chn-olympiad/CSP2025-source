#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 100010;
int T,n,xps[4],ans,b[MAXN],k;
priority_queue<pair<int,int> >spk[4];
priority_queue<int>ts;
struct node{
	int x,y,z;
	int mx_id;
	int mid_id;
	int mn_id;
}a[MAXN];
int ysp_mx(node val){
	if(val.x > val.y){
		if(val.x > val.z) return 1;
		else if(val.z > val.y) return 3;
		else return 1;
	}
	else{
		if(val.y > val.z) return 2;
		else if(val.z > val.x) return 3;
		else return 2;
	}
}
int ysp_mid(node val){
	if(val.x > val.y){
		if(val.y > val.z) return 2;
		else{
			if(val.z < val.x) return 3;
			else return 1;
		}
	}
	else{
		if(val.x > val.z) return 1;
		else{
			if(val.z < val.y) return 3;
			else return 2;
		}
	}
}
int ysp_mn(node val){
	if(val.x > val.y){
		if(val.y > val.z) return 3;
		else return 2;
	}
	else{
		if(val.x > val.z) return 3;
		else return 1;
	}
}
void yz(int step){
	while(!spk[step].empty()){
		ans += spk[step].top().first;
		spk[step].pop();
		xps[step]--;
		if(!xps[step]) break;
	}
	while(!spk[step].empty()){
		b[++k] = spk[step].top().second;
		spk[step].pop();
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> T;
	while(T--){
		ans = 0;
		cin >> n;
		if(n == 2){
			cin >> a[1].x >> a[1].y >> a[1].z;
			cin >> a[2].x >> a[2].y >> a[2].z;
			if(ysp_mx(a[1]) == ysp_mx(a[2])){
				int n1,n2,n3,n4;
				if(ysp_mx(a[1]) == 1) n1 = a[1].x;
				if(ysp_mx(a[1]) == 2) n1 = a[1].y;
				if(ysp_mx(a[1]) == 3) n1 = a[1].z;
				if(ysp_mx(a[2]) == 1) n2 = a[2].x;
				if(ysp_mx(a[2]) == 2) n2 = a[2].y;
				if(ysp_mx(a[2]) == 3) n2 = a[2].z;
				if(ysp_mid(a[1]) == 1) n3 = a[1].x;
				if(ysp_mid(a[1]) == 2) n3 = a[1].y;
				if(ysp_mid(a[1]) == 3) n3 = a[1].z;
				if(ysp_mid(a[2]) == 1) n4 = a[2].x;
				if(ysp_mid(a[2]) == 2) n4 = a[2].y;
				if(ysp_mid(a[2]) == 3) n4 = a[2].z;
				if(n1 + n4 > n2 + n3){
					cout << n1 + n4 << endl;
				}
				else{
					cout << n3 + n2 << endl;
				}
			}
			else{
				cout << max(a[1].x,max(a[1].y,a[1].z)) + max(a[2].x,max(a[2].y,a[2].z)) << endl;
			}
			continue;
		}
		xps[1] = xps[2] = xps[3] = n / 2;
		bool flag = 1;
		for(int i = 1; i <= n; i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			if(a[i].y || a[i].z) flag = 0;
			a[i].mx_id = ysp_mx(a[i]);
			a[i].mid_id = ysp_mid(a[i]);
			a[i].mn_id = ysp_mn(a[i]);
			if(a[i].mx_id == 1) spk[1].push(make_pair(a[i].x,i));
			if(a[i].mx_id == 2) spk[2].push(make_pair(a[i].y,i));
			if(a[i].mx_id == 3) spk[3].push(make_pair(a[i].z,i));
		}
		if(flag){
			for(int i = 1; i <= n; i++){
				ts.push(a[i].x);
			}
			for(int i = 1; i <= n / 2; i++){
				ans += ts.top();
				ts.pop();
			}
			cout << ans << endl;
			continue;
		}
		yz(1),yz(2),yz(3),k = 0;
		for(int i = 1; i <= k; i++){
			if(a[b[i]].mid_id == 1) spk[1].push(make_pair(a[i].x,i));
			if(a[b[i]].mid_id == 2) spk[2].push(make_pair(a[i].y,i));
			if(a[b[i]].mid_id == 3) spk[3].push(make_pair(a[i].z,i));
		}
		yz(1),yz(2),yz(3),k = 0;
		for(int i = 1; i <= k; i++){
			if(a[b[i]].mn_id == 1) spk[1].push(make_pair(a[i].x,i));
			if(a[b[i]].mn_id == 2) spk[2].push(make_pair(a[i].y,i));
			if(a[b[i]].mn_id == 3) spk[3].push(make_pair(a[i].z,i));
		}
		yz(1),yz(2),yz(3),k = 0;
		cout << ans << endl;
	}
	return 0;
}

