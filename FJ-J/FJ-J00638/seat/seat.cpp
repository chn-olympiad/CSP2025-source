#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,m,w[N*N],xr;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>w[i];
		if(i==1){
			xr=w[i];
		}
	}
	sort(w+1,w+1+n*m,cmp);
	int cnt=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(w[cnt]==xr){
					printf("%d %d",i,j);
					return 0;
				}
				cnt++;
			}
		}else{
			for(int j=n;j>=1;j--){
				if(w[cnt]==xr){
					printf("%d %d",i,j);
					return 0;
				}
				cnt++;
			}
		}
	}
	return 0;
}
