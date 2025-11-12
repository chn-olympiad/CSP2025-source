#include<bits/stdc++.h>
using namespace  std;

int n, m, a[15][15], b[105], k = 1, sum;

bool cmp(int x, int y){
	if(x > y){
		return true;
	}
	return false;
}

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin>>n>>m;
    for(int i = 1; i <= n*m; i++){
		cin>>b[i];
	}
	sum = b[1];
	sort(b + 1, b + n*m + 1, cmp);
	for(int i = 1; i <= m; i = i){
		for(int j = 1; j <= n && k <= n*m; j = j){
			a[j][i] = b[k];
			if(a[j][i] == sum){
				cout<<i<<" "<<j;
				return 0;
			}
			k++;
			if(i%2 == 1){
				if(j == n){
					i++;
				}else{
					j++;
				}
			}else{
				if(j == 1){
					i++;
				}else{
					j--;
				}
			}
		}
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
