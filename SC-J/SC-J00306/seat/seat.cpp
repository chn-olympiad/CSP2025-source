#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int tmp[105];
int cmp(int a,int b){
	return a > b;
};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat","w",stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n*m; i ++){
		cin >> tmp[i];
	}
	int xr = tmp[0];
	sort(tmp,tmp+n*m,cmp);
	int id = 0;
	for(int i = 0; i < m; i ++){
		if(i % 2){
			for(int j = n-1; j >= 0; j --){
				a[j][i] = tmp[id++];
			}
		} else {
			for(int j = 0; j < n; j ++){
				a[j][i] = tmp[id++];
			}
		}
	}
	
	for(int i = 0; i < m; i ++){
		for(int j = 0; j < n; j ++){
			if(xr == a[j][i]){
				cout << i+1 << " " << j+1;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}