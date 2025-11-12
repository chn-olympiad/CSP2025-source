#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n,m,ans;
int a[N][3];

void dfs(int dep,int x,int y,int z,int val){
	if(dep > n || (x >= m && y >= m && z >= m)){
		ans = max(ans,val);
		return;
	}
	if(x < m){
		dfs(dep+1,x+1,y,z,val+a[dep][0]);
	}
	if(y < m){
		dfs(dep+1,x,y+1,z,val+a[dep][1]);
	}
	if(z < m){
		dfs(dep+1,x,y,z+1,val+a[dep][2]);
	}
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	int t;
    cin >> t;
    while(t--){
        cin >> n;
        m = n / 2;
        ans = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i][0] >> a[i][1] >> a[i][2];
        }
        dfs(1,0,0,0,0);
        cout << ans << endl;
    }
    return 0;
}
