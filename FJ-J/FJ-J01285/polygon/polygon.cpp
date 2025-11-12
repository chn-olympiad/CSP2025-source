#include<bits/stdc++.h>
using namespace std;

int n,a[5005],ans = 0,mod = 998244353,vis[5005];

set< multiset<int> > s;
multiset<int> ms; 
 
void dfs(int now,int edge,int sum,int maxn){
	if(now == edge){ 
		if(sum > 2*maxn){
			s.insert(ms);
			ans++;
			ans %= 998244353;
		}
		return;
	}
	for(int i = 1; i <= n; i++){
		if(vis[i]){
			continue;
		}
		vis[i] = true; 
		ms.insert(i);
		dfs(now+1,edge,sum+a[i],max(maxn,a[i]));   
		vis[i] = false;
		ms.erase(ms.find(i));
	}
}

int main(){ 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin >>n;
	if(n <= 3){
		if(n < 3){
			cout <<"0";
			return 0;
		}
		int a,b,c;
		cin >>a >>b >>c;
		int m = max({a,b,c});
		if(a+b+c <= 2*m){
			cout <<"0";
			return 0;
		}
		cout <<1;
		return 0;
	} 
	for(int i = 1; i <= n; i++){
		cin >>a[i];
	}
	for(int i = 3; i <= n; i++){ 
		ms.clear();
		dfs(1,i,0,0);
	}
	cout <<s.size()+1;
	return 0;
} 
 
