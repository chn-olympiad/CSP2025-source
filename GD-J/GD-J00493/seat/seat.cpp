#include<bits/stdc++.h>
using namespace std;
const int N = 1e4;
int n,m,a[N],b[N][N],f;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n*m;i++){
		scanf("%d",&a[i]);
		if (i == 1) f = a[i];
	}
	bool k = true;
	int cnt = n*m;
	sort(a+1,a+n*m+1);
	for(int j = 1;j <= m;j++){
		if(k){
			for(int i = 1;i <= n;i++){
				b[i][j] = a[cnt];
				if(a[cnt] == f){
				printf("%d %d",j,i);
				return 0;
				}
				cnt -= 1;
			}
			k = false;
		}else {
			for(int i = n;i >= 1;i--){
				b[i][j] = a[cnt];
				if(a[cnt] == f){
				 printf("%d %d",j,i);
				 return 0;
				}
				cnt -= 1;
				k = true;
			}
		}
		
	}
	return 0;
}
