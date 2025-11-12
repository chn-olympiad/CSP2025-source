#include<bits/stdc++.h>
using namespace std;
int n,m,tot,a[110],ans[11][11];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	int R=a[1];
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[++tot]==R){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else if(i%2==0){
			for(int j=n;j>=1;j--){
				if(a[++tot]==R){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
