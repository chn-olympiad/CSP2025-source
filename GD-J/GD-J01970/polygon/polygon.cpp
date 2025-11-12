#include<bits/stdc++.h>
using namespace std;

int n,a[5005];

int mis[5005],ans = 0;



void dfs(int h,int now,int ax,int all){
	
	if(h >= 3){
		
		if(all > ax * 2){
			ans++;
			
//			for(int i = 1; i <= h; i++){
//				cout<<mis[i]<<" ";
//			}
//			cout<<'\n';
		}
		
	}
	
	if(now == n){		
		return;
	}
	
	
	
	for(int i = now + 1; i <= n; i++){
	
//		mis[h+1] = i;
		dfs(h+1,i, max(ax,a[i]) , all + a[i]);

	}
	
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	dfs(0,0,-1,0);
	
	cout << ans << '\n';
	
	return 0;
}
