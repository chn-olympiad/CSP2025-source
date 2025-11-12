#include <bits/stdc++.h>
using namespace std;
const int MAXN=20;
const int MAXM=20;
const int MAXB=200;
int a[MAXB];
int jz[MAXN][MAXM];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int xiaor=a[1];
	sort(a+1,a+1+n*m,cmp);
	//int cnt=0;
	for(int i=1;i<=m;i++){ //di yi lie kai shi
		//cnt++;
		if(i%2==1){
			for(int j=1;j<=n;j++){
				jz[j][i]=a[(i-1)*n+j];
			}
		}else{
			for(int j=n;j>=1;j--){
				jz[j][i]=a[(i-1)*n+(n-j+1)];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(jz[i][j]==xiaor){
				cout<<j<<' '<<i;
				break;
			}
		}
	}
	return 0;
}
