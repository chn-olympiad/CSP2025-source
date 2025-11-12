#include<bits/stdc++.h>
using namespace std;
int a[100][100],b[10000][10000];
int n,m;
int d[10000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int c,r,cnt = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin >> a[i][j];
			d[cnt] = a[i][j];
			cnt++;
		}
	}
	int an = a[1][1];
	sort(d,d+1+m*n);
	cnt = n*m;
	for(int i = 1;i <=n;i++){
		if(i%2 == 1){
			for(int j = 1;j <= m;j++){
				b[i][j] = d[cnt];
				cnt--;
				if(b[i][j] == an){
					c = i;
					r = j;
					break;
				}
			}
		}else if(i%2 == 0){
			for(int j = m;j >= 1;j--){
				b[i][j] = d[cnt];
				cnt--;
				if(b[i][j] == an){
					c = i;
					r = j;
					break;
				}
			}
		}
	}
	cout << c << " "<< r;
	return 0;
}
