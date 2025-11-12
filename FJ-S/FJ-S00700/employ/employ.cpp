#include<bits/stdc++.h>
using namespace std;
int n,m,a[501],c[501];
int csh[501];
int p[25001][501];
int l;
void dfs(int step,int w[]){
	if(step == n){
		for(int i = 1;i<=n;i++){
			p[l][i] = w[i];
		}
		l++;
	}else{
		int t[step+1];
	for(int i = 1;i<=step;i++){
		t[i] = w[i];
	}
	if(step < n){
		for(int i = 1;i<=n;i++){
			if(!book[i]){
				book[i] = true;
				t[i+1] = i; 
				dfs(step+1,t);
				book[i] = false;
			}
		}
	} 
	}
	
}


int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	csh[1] = 1;
	for(int i = 1;i<501;i++){
		csh[i] = csh[i-1]*i;
	}
	cin>>n>>m;
	l = 0;
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	
	for(int i = 0;i<n;i++){
		cin>>c[i];
	}
	
	
	int ans = 0;
	for(int i = 0;i<n*n;i++){
		int lj = 0;
		int sum = 0;
		for(int j = 0;j<n;j++){
			if(lj>c[p[i][j]]){
				lj++;
				continue;
			}
			
			if(a[j] == 0) lj++;
			else{
				lj = 0;
				sum++;
			}
		}
		if(m <= sum) ans++;
	}
	
	cout<<ans;
	return 0;
}
