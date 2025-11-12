#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[205],b[25][25];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int ans=a[1];
	sort(a+1,a+1+n*m,cmp);
	int p=1;
	for(int i=1;i<=m;i++){
		if(i%2==1)for(int j=1;j<=n;j++)b[j][i]=a[p++];
		else for(int j=n;j>=1;j--)b[j][i]=a[p++];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==ans){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
