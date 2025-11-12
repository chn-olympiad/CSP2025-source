#include <bits/stdc++.h>
using namespace std;
int t,x;
int fp(int n){
	int a[n+1][4];
	int b[n*3 + 2];
	int qh = 0;
	for(int i = 1; i <= n; i++){
		for (int j = 1; j <= 3; j++){
			scanf("%d",&a[i][j]);
		}
	}
	b[1]=a[1][1]+a[2][2];
	b[2]=a[1][1]+a[2][3];
	b[3]=a[1][2]+a[2][1];
	b[4]=a[1][2]+a[2][3];
	b[5]=a[1][3]+a[2][1];
	b[6]=a[1][3]+a[2][2];
	qh=b[1];
	for(int i = 1; i <= 6;i++){		
		if(qh < b[i]){
			qh = b[i];
		}
	}
	return qh;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	int tj[t];
	for(int i = 1; i <= t; i++){
		scanf("%d",&x);
		tj[i] = fp(x);		
	}
	for(int i = 1; i <= t; i++){
		printf("%d\n",tj[i]);		
	}
	return 0;	
}
