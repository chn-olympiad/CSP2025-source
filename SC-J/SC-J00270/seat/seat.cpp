#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[1005],b[N][N],k,n,m,cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	int flag=0;
	for(int i=1;i<=m*n;i++)cin>>a[i];
	k=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int j=1;j<=n;j++){
		if(flag==0){
		for(int i=1;i<=m;i++){
		b[i][j]=a[++cnt];
		if(i==m)flag=1;
		}
	}
		else {
		for(int i=m;i>=1;i--){
		b[i][j]=a[++cnt];
		if(i==1)flag=0;
		}
	}
		
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(k==b[i][j]){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	
	return 0;
}