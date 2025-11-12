#include<bits/stdc++.h>
using namespace std;
long long a[107],b[17][17];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,i,j,d=1;
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>a[i];
	}
	long long c=a[1];
	sort(a+1,a+1+n*m,cmp);
	long long x,y;
	for(i=1;i<=m;i++){
		if(i%2==1){
			for(j=1;j<=n;j++){
				b[j][i]=a[d++];
			}
		}else{
			for(j=n;j>=1;j--){
				b[j][i]=a[d++];
			}
		}
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(b[i][j]==c){
				y=i;
				x=j;
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
} 
