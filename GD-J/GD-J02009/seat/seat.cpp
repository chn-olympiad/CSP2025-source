#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,k;
LL a[110],ans[15][15];
bool cmp(LL x,LL y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	LL r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				ans[i][j]=a[++k];
				if(ans[i][j]==r){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else if(i%2==0){
			for(int j=m;j>=1;j--){
				ans[i][j]=a[++k];
				if(ans[i][j]==r){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
