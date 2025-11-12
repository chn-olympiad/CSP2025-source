#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,k=0,ans,a[1005];
bool cmp(int x,int y){return x>y;}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ont","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	memset(a,0,sizeof(a));
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	ans=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(a[++k]==ans){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=m;j>=1;j--){
				if(a[++k]==ans){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}