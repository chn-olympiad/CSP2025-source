#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,op=1;
int a[15][15],num[110];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&num[i]);
	}
	cnt=num[1];
	sort(num+1,num+n*m+1,cmp);
	for(int i=1;i<=m;i++){ 
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[i][j]=num[op];
				op++;
			}
		}
		else{
			for(int j=n;j>=1;--j){
				a[i][j]=num[op];
				op++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==cnt){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
}

