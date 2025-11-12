#include <bits/stdc++.h>
using namespace std;
int n,ans=0;
int a[5005];
bool c[5005];
void dfs(int x,int y,int z){
	c[z]=1;
	if(y==x){
		int cnt=0,maxn=0;
//		if(x==3){
//			for(int i=1;i<=n;i++){
//				if(c[i]==1){
//					cout << a[i] << " ";
//				}
//			}
//			cout << endl;
//		}
		for(int i=1;i<=n;i++){
			if(c[i]==1){
				cnt+=a[i];
				maxn=max(maxn,a[i]);
			}
		}
		if(cnt>2*maxn){
			ans++;
			ans%=998244353;
//			for(int i=1;i<=n;i++){
//				if(c[i]==1){
//					cout << a[i] << " ";
//				}
//			}
//			cout << endl;
		}
	}
	for(int i=z+1;i<=n;i++){
		if(c[i]==0){
			c[i]=1;
			dfs(x,y+1,i);
			c[i]=0;
		}
		c[i]=0;
	}
	c[z]=0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			dfs(i,1,j);
		}
	}
	cout << ans << endl;
	return 0;
}
/*
5
1 2 3 4 5
5
2 2 3 8 10
20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1
*/
/*

*/ 
