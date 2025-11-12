#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll h,l,jf;
}a[1005];
bool cmp(node x,node y){
	return x.jf>y.jf;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll m,n,cim=0,r=0,b[105][105];
	cin>>n>>m;
	cim=n*m;
	for(ll i=1;i<=cim;i++){
		cin>>a[i].jf;
	}
	ll cum=1;
	r=a[1].jf;
	sort(a+1,a+1+cim,cmp);
	for(ll i=0;i<=m;i++){
		for(ll j=1;j<=n;j++){
			a[cum].jf=b[i][j];
			cum++;
			if(b[i][j]==r){
				cout<<i<<" "<<j;
				return 0;
			}
		}
		i++;
		for(ll z=n;z>=1;z--){
			a[cum].jf=b[i][z];
			cum++;
			if(b[i][z]==r){
				cout<<i<<" "<<z;
				return 0;
			}
		}
	}
	return 0;
}
