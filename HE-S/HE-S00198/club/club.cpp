#include<bits/stdc++.h>
using namespace std;
long tt,n,t[4];
long long ans = 0;
struct stu{
	int p[5],num;
};
stu a[1000000];
long long maxn;
bool f[1000000];

bool p(){
	for(int i = 1;i <= 3;i++){
		if(t[i] > n/2){
			return 0;
		}
	} 
	return 1;
}

void web(int x){
	if(x > n){
		maxn = max(ans,maxn);
		return;
	}
	for(int i = 1;i <= 3;i++){
			t[i]++;
			ans += a[x].p[i];
			if(p()){
				web(x + 1);
			}
			t[i]--;
			ans -= a[x].p[i];
		
	} 
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> tt;
	for(int i = 1;i <= tt;i++){
		cin >> n;
		ans = 0;
		maxn = -1;
		for(int i = 1;i <= n;i++){
			cin >> a[i].p[1] >> a[i].p[2] >> a[i].p[3];
			a[i].num = i;
		} 
		web(1);
		cout << maxn << "\n";
	}
	
	
	return 0;
} 
