#include<bits/stdc++.h>

using namespace std;
bool cmd(int a, int b){
	return a>b;
}

int main(){
	freopen("seat3.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m;
	cin>>n>>m;
	int cj, dx[106];
	for(int i = 1; i<=n*m; i++){
		cin>>dx[i];
	}
	cj = dx[1];
	
	sort(&dx[1], dx+n*m+1, cmd);
	
	int sum = 0;
	for(int i = 1; i<=m; i++){
		if(i%2 == 1){
			for(int j = 1; j<=n; j++){
				sum++;
				if(dx[sum] == cj){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j = n; j>=1; j--){
				sum++;
				if(dx[sum] == cj){
					cout<<i<<" "<<j;
					return 0;
				}
			}	
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
