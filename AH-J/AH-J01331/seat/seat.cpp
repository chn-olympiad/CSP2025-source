#include<bits/stdc++.h>
using namespace std;
int n,m,a[120],pos,b[120][120],cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	pos=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				b[i][j]=a[++cnt];
			}
		}else{
			for(int i=n;i>=1;i--){
				b[i][j]=a[++cnt];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==pos){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
