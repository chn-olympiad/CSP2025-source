#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],b[100005][100005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n * m; i++){
		scanf("%d",&a[i]);
	}
	int xx = 1;
	for(int i = 1; i <= m; i++){
		if(i % 2 != 0){
			for(int j = 1; j <= n; j++){
				b[j][i] = xx;
				xx++;
			}
		} else {
			for(int j = n; j >= 1; j--){
				b[j][i] == xx;
				xx++;
			}
		}
	}
	int x = a[1],cnt = 0;
	sort(a+1,a+n*m+1);
	for(int i = n * m; i >= 1; i--){
		cnt++;
		if(a[i] == x){
			break;
		}
	}
	for(int i = 1; i <= m;i++){
		for(int j = 1; j <= n; j++){
			if(b[j][i] == cnt){
				printf("%d %d",i,j);
			}
		}
	}
	return 0;
}
