#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[110],ans,b[20][20];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+1+n*m,cmp);
	int x=1;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				b[i][j]=a[x];
				x++;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				b[i][j]=a[x];
				x++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==ans){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
} 
