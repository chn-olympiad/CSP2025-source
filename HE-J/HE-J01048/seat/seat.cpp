#include<bits/stdc++.h>
using namespace std;
const int N=1100;
int n,m;
int a[N];
int ans[110][110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int cnt=1;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int mm=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++) ans[i][j]=a[cnt++];
		}
		else{
			for(int i=n;i>=1;i--) ans[i][j]=a[cnt++];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]==mm){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
