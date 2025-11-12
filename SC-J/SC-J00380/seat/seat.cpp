#include <bits/stdc++.h>
using namespace std;
int n,m,a[10000],b[100][100],x,cnt;
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
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		int f=i&1;
		if(f){
			for(int j=1;j<=m;j++){
				b[i][j]=a[++cnt];
			}
		}else{
			for(int j=m;j>=1;j--){
				b[i][j]=a[++cnt];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==x){
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}
	return 0;
}