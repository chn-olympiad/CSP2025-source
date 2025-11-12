#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
bool cmp(long long a,long long b){
	return a > b;
}
int a[10100];
int pos[50][50];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++) cin >> a[i];
	int R_score = a[1];
	sort(a + 1,a + 1 + n * m,cmp);
	int a_n = 0;
	for(int i = 1;i <= m;i++){
		if(i % 2 != 0){
			for(int j = 1;j <= n;j++){
				a_n++;
				pos[j][i] = a[a_n];
			}
		}
		else if(i % 2 == 0){
			for(int j = n;j >= 1;j--){
				a_n++;
				pos[j][i] = a[a_n];
			}
		}
	}
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			//cout << pos[i][j] << ' ';
			if(pos[i][j] == R_score){
				cout << j << ' ' << i;
				break;
			}
		}
		//cout << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
