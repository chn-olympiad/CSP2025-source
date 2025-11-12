#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,f[15][15],d,dx[10]={1,-1},r,a[105],i,j;

bool cmp(const ll &x,const ll &y){return x>y;}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>r;
	a[1]=r;
	for(i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	i=1,j=1;
	for(ll k=1;k<=n*m;k++){
		f[i][j]=a[k];
		if(d==0){
			if(i+1>n){
				d=1,j++;
			}else i++;
		}else{
			if(i-1<1){
				d=0,j++;
			}else i--;
		}
	}for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(f[i][j]==r){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
