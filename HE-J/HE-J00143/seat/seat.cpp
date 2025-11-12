#include <bits/stdc++.h>
using namespace std;

long long n,m,cj,llen;
long long a[210],b[21][21];

bool cmp(long long q,long long w){
	return q>w;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n*m;i++){
		cin >> a[i];
	}
	cj = a[1];
	sort(a+1,a+n*m+1,cmp);
	llen = 0;
	for(int i = 1;i<=m;i++){
		if(i % 2 == 1){
			for(int j = 1;j<=n;j++){
				b[i][j] = a[++llen];
				if(a[llen] == cj){
					cout << i << " "<<j;
					return 0;
				}
			}
		}else{
			for(int j = n;j>=1;j--){
				b[i][j] = a[++llen];
				if(a[llen] == cj){
					cout << i << " "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
