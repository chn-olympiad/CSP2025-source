#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,sum1=0,sum2=0,sum3=1,sum4=0;
int a[100001];
int b[101][101];
signed main(){
	freopen("seat.in","l",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum1=(n*m);
	for(int i=1;i<=(n*m);i++) cin>>a[i];
	sum4=a[1];
	sort(a+1,a+1+(n*m));
	for(int i=1;i<=((m*n)/2);i++){
		sum2=a[i];
		a[i]=a[sum1];
		a[sum1]=sum2;
		sum1--;
	}	
	for(int i=1;i<=m;i++){
		if((i%2)!=0){
			for(int j=1;j<=n;j++){
				b[j][i]=a[sum3];
				sum3++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				b[j][i]=a[sum3];
				sum3++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==sum4){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}