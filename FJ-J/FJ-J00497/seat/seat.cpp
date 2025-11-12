#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000010],x[110][100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int sum = a[1],k;
	sort(a+1,a+1+n*m,greater<int>());
	for(int j = 1;j<=n;j++){
		if(j%2==1){
			for(int i = 1;i<=m;i++){
				x[i][j] = a[k];
				k++;
			}
			continue;
		}
		if(j%2==0){
			for(int i = m;i>=1;i--){
				x[i][j] = a[k];
				k++;
			}
			continue;
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(x[i][j]==sum){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	return 0;
} 
