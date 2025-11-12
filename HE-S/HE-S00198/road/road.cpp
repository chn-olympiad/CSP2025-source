#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int  ans[1000000];
long long  anss = 0;
int b[100000];
int v,u,val;
struct stu{
	int u,v,val;
};
stu a[1000000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> a[i].u >> a[i].v >> a[i].val;
		if(ans[a[i].u] == 0){
			ans[a[i].u] = a[i].val;
		}
		else{
			ans[a[i].u] = min(ans[a[i].u],a[i].val);
		}
		if(ans[a[i].v] == 0){
			ans[a[i].v] = a[i].val;
		}
		else{
			ans[a[i].v] = min(ans[a[i].v],a[i].val);
		}
	}
	int x;
	for(int i = 1;i <= k;i++){
		cin >> b[i];
		for(int j = 1;j <= n;j++){
			cin >> x;
			ans[j] = min(ans[j],x);
		}
	}
	for(int i = 1;i <= n + k;i++){
		anss += ans[i];
	} 
	cout << anss;
	return 0;
} 
