#include<bits/stdc++.h> 
using namespace std;
const int N = 1e3;
int n,m;
int a[10000];
int b[N][N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	int num = a[1];
	sort(a + 1,a + n*m + 1,greater<int>());
	int k = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(i % 2){
				b[j][i] = a[k++];
			}
			else{
				b[m - j + 1][i] = a[k++];
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++)
			if(b[i][j] == num)
				cout << j << ' ' << i;
	}
		
	return 0;			

}
