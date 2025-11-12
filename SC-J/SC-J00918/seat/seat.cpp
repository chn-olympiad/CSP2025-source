#include<bits/stdc++.h>
using namespace std;
int a[15];
int b[11][11];
bool cmp(int a,int b){
	if(a>b)return 1;
	else return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int x=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)x=a[i];
	}
	sort(a+1,a+m*n+1,cmp);
	int indx=0;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				indx++;
				b[i][j]=a[indx];
			}
		}else{
			for(int i=n;i>=1;i--){
				indx++;
				b[i][j]=a[indx];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==x){
				cout<<i<<" "<<j;
				break;
			}
		}
	}
	return 0;
}