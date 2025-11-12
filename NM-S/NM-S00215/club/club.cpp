#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,mx; 
int a,b,c,ai,bi,ci;
int q[3][N];
int to[3][2]={{1,1},{2,1},{3,1}};
void dfs(int x){
	if(x==n){
		mx=max(mx,a+b+c);
		return;
	}
	for(int i=1;i<=3;i++){
		for(int j=x;j<=n;j++){
		if(ai+1<n/2){
			a+=q[i][j];
			ai++;
			dfs(x+1);
		}
		if(bi+1<n/2){
			b+=q[i][j];
			bi++;
			dfs(x+1);
		}
		if(ci+1<n/2){
			c+=q[i][j];
			ci++;
			dfs(x+1);
		}
		
		
	}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		mx=0;
		a=0;b=0;c=0;ai=0;bi=0;ci=0;
		cin >> n;
		for(int i=1;i<=3;i++){
			for(int j=1;j<=n;j++){
				cin >> q[i][j];
			}
		}
		for(int i=1;i<=n;i++)dfs(i);
		cout << mx << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}