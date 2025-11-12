#include<bits/stdc++.h>
using namespace std;
int n,m,num[105],number,ans[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>number;
	num[1]=number;
	for(int i=2;i<=n*m;i++){
		cin>>num[i];
	}
	sort(num+1,num+n*m+1,cmp);
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(j%2==1){
				ans[j][i]=num[i+(j-1)*n];
			}
			else{
				ans[j][n-i+1]=num[(j-1)*n+i];
			}
		}
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(j%2==1){
				if(ans[j][i]==number){
					cout<<j<<" "<<i;
					return 0;
				}
			}
			else{
				if(ans[j][n-i+1]==number){
					cout<<j<<" "<<n-i+1;
					return 0;
				}
			}
		}
	}
}
