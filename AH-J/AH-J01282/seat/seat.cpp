#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005],ai;
int room[105][105];
bool cmp(int xx,int yy){
	return xx>yy;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			cin >> a[++ai];
		}
	}
	int ans=a[1];
	sort(a+1,a+ai+1,cmp);
	int now=0;
	for(int i = 1; i <= m; ++i){
		if(i%2==0){
			for(int j = n; j >= 1; --j){
				room[j][i]=a[++now];
			}
		}else{
			for(int j = 1; j <= n; ++j){
				room[j][i]=a[++now];
			}
		}
	}
	bool used=false;
	for(int i = 1; i <= n; ++i){
		if(used) break;
		for(int j = 1; j <= m; ++j){
			if(room[i][j]==ans){
				cout << j << " " << i;
				used=true;
				break;
			} 
		}
	}
	return 0;
}
