#include<bits/stdc++.h>
using namespace std;

long long n,a[100005][4];

long long ans = 0;

void dfs(int now,int A,int B,int C,long long out){
	
	if(now == n + 1){
		ans = max(ans,out);
		return ;
	}
	
	if(A < n / 2){
		dfs(now + 1, A + 1,B,C,out + a[now][1]);
	}
	if(B < n / 2){
		dfs(now + 1, A,B + 1,C,out + a[now][2]);
	}
	if(C < n / 2){
		dfs(now + 1, A,B,C + 1,out + a[now][3]);
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	
	while(t--){
		cin>>n;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				
				cin>>a[i][j];
				
			}
		}
		
		dfs(1,0,0,0,0);
		
		cout << ans << '\n';
		ans = 0;
	}
	
	return 0;
} 
