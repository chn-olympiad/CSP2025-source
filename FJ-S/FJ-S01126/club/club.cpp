#include<bits/stdc++.h>
using namespace std;

struct node{
	int a,b,c; 
};

bool cmp1(node x,node y){
	return x.a > y.a;
}

bool cmp2(node x,node y){
	return x.b > y.b;
}

bool cmp3(node x,node y){
	return x.c > y.c;
}

void solve(){
	int n,ans1 = 0,ans2 = 0,ans3 = 0;
	cin >>n;
	if(n == 2){
		int a,b,c,d,e,f;
		cin >>a >>b >>c >>d >>e >>f;
		cout <<max({a+e,a+f,b+d,b+f,c+d,c+e}) <<endl;
		return;
	}
	node k[n+1];
	bool flaga = true,flagb = true; 
	for(int i = 1; i <= n; i++){
		cin >>k[i].a >>k[i].b >>k[i].c;
		if(k[i].b || k[i].c){
			flaga = false;
		}
		if(k[i].c){
			flagb = false;
		}
	}
	if(flaga){
		sort(k+1,k+n+1,cmp1);
		int ans = 0;
		for(int i = 1; i <= n/2; i++){
			ans += k[i].a;
		}
		cout <<ans <<endl;
		return;
	}
	if(flagb){
		sort(k+1,k+n+1,cmp1);
		for(int i = 1; i <= n/2; i++){
			ans1 += k[i].a;
		}
		for(int i = n/2+1; i <= n; i++){
			ans1 += k[i].b;
		}
		sort(k+1,k+n+1,cmp2);
		for(int i = 1; i <= n/2; i++){
			ans2 += k[i].b;
		}
		for(int i = n/2+1; i <= n; i++){
			ans2 += k[i].a;
		}
		cout <<max(an1,ans2) <<endl;
		return;
	}
	sort(k+1,k+n+1,cmp1);
	for(int i = 1; i <= n/2; i++){
		ans1 += k[i].a;
	}
	for(int i = n/2+1; i <= n; i++){
		ans1 += max(k[i].b,k[i].c);
	}
	sort(k+1,k+n+1,cmp2);
	for(int i = 1; i <= n/2; i++){
		ans2 += k[i].b;
	}
	for(int i = n/2+1; i <= n; i++){
		ans2 += max(k[i].a,k[i].c);
	}
	sort(k+1,k+n+1,cmp3);
	for(int i = 1; i <= n/2; i++){
		ans3 += k[i].c;
	}
	for(int i = n/2+1; i <= n; i++){
		ans3 += max(k[i].a,k[i].b);
	}
	cout <<max({ans1,ans2,ans3}) <<endl;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >>t;
	while(t--){
		solve();
	}
	return 0;
} 
