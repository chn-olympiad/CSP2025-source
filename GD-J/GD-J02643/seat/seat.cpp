#include<bits/stdc++.h>
using namespace std;
int n,m,r;
int a[110],ans[20][20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1);
	int x=n*m;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[x]==r){
					cout<<i<<" "<<j;
					return 0;
				}
				ans[j][i]=a[x];
				x--;
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[x]==r){
					cout<<i<<" "<<j;
					return 0;
				}
				ans[j][i]=a[x];
				x--;
			}
		}
	}
	return 0;
}
