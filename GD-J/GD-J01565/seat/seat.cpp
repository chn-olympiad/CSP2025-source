#include<bits/stdc++.h>
using namespace std;
int a[110];
int b[20][20];
int main(){
	int n,m;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int r=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for (int i=1;i<=n*m;i++){
		if (a[i]==r){
			int col=(i-1)/n+1;
			int row=(i-1)%n+1;
			if (col%2==0){
				row=n-row+1;
			}
			printf("%d %d",col,row);
			return 0;
		}
	}
	return 0;
}
