#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[5010];
ll ans;

bool vis[5010];
void d(int x){
	if(x > n){
		vector<int> p;
		for(int i = 1;i <= n;i++){
			if(vis[i] == 1){
				p.push_back(i);
			}
		}
		if(p.size() >= 3){
			ll cnt = 0;
			int ma = 0;
			for(int i = 0;i < p.size();i++){
				cnt += a[p[i]];
				ma = max(a[p[i]],ma);
			}
			if(cnt - ma > ma){
				ans++;
			}
		}
		return;
	}
	vis[x] = 1;
	d(x+1); 
	vis[x] = 0;
	d(x+1);
}

ll C(int x,int y){
	ll cnt = 1;
	for(int i = x - y + 1;i <= x;i++){
		cnt *= i;
	}
	for(int i = 1;i <= y;i++){
		cnt /= i;
	}
	return cnt;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool f = 0;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i] > 1) f = 1;
	}
	if(f == 1){
		d(1);
		cout<<ans;
	}else{
		for(int i = 3;i <= n;i++){
			ans += C(n,i);
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

