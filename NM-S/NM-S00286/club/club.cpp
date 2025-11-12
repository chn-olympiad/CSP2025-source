#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;

int degree[N][3];
int n;
int solve(){
	int temp[N];
	int res = 0;
	int i=0;
	while(i<n){
		for(int j=0;j<3;j++){
			if(degree[i][j]>=degree[i][j+1]&&degree[i][j]>=degree[i][j+2]){
				temp[i] = degree[i][j];
			}if(degree[i][j+1]>=degree[i-1][j]&&degree[i][j+1]>=degree[i][j+2]){
				temp[i] = degree[i][j+1];
			}else{
				temp[i] = degree[i][j+2];
			}
		}
		i++;
	}
	for(int i=0;i<n;i++){
		res += temp[i];
	}
	return res;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0;
	int res[N];
	cin >> t;
	cin >> n;
	int i=0;
	while(t>0){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin >> degree[i][j];
			}
		}
		i++;
		res[i] = solve();
		t--;
	}
	for(int i=0;i<t;i++){
		cout << res[i];
	}
	return 0;
}
