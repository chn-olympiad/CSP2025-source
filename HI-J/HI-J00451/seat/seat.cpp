#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,sum=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int h=a[1];
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				b[i][j]=a[sum];
				if(h==a[sum]){
					cout<<i<<' '<<j;
					return 0;
				}
				sum++;
			}
		}else{
			for(int j=1;j<=n;j++){
				b[i][j]=a[sum];
				if(h==a[sum]){
					cout<<i<<' '<<j;
					return 0;
				}
				sum++;
			}	
		}
	}
	return 0;
}
