#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
ll n,m,a[1005],b[105][105],x,y=2,l=2,r=1,ans;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	x=n*m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1&&j==1)b[i][j]=1;
			else if(i==1){
				if(j%2==0){
					b[i][j]=b[i][j-1]+2*n-1;
				}
				else{
					b[i][j]=b[i][j-1]+1;
				}
			}
			else{
				if(j%2==0){
					b[i][j]=b[i-1][j]-1;
				}
				else{
					b[i][j]=b[i-1][j]+1;
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<b[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			b[i][j]=a[b[i][j]];
			if(b[i][j]==ans){
				return cout<<j<<' '<<i,0;
			}
		}
	}
	return 0;
}
