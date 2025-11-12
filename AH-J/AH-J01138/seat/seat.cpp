#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(int const &x,int const &y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll m,n,xm,sum;
	ll a[10010];
	ll s[110][110];
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	xm=a[1];
	sort(a+1,a+1+sum,cmp);
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(j%2==0){
				s[i][j]=a[(j-1)*n+(n-i+1)];
			}else{
				s[i][j]=a[(j-1)*n+i];
			}
			if(s[i][j]==xm){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
