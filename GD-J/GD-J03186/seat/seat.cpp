#include<bits/stdc++.h>
using namespace std;
int a[20][20],b[120];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k,t = 1,p;
	cin >> n >> m >> p;
	k = n * m;
	b[1] = p;
	for(int i = 2;i <= k;i++)
		cin >> b[i];
	sort(b + 1,b + k + 1,cmp);
	for(int i = 1;i <= m;i++){
		if(i % 2 != 0){
			for(int j = 1;j <= n;j++){
				a[j][i] = b[t];
				t++;
			}
		}
		else{
			for(int j = n;j >= 1;j--){
				a[j][i] = b[t];
				t++;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++)
			if(a[i][j] == p)
				cout << j << ' ' << i;
	}
	return 0;
}
