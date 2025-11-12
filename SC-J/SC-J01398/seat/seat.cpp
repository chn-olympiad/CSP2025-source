#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,xpe,ansx,ansy;
struct peo{
	int v;
	int b;
}a[110];
bool cmp(peo a,peo b){
	return a.v>b.v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].v;
		a[i].b=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].b==1){
			xpe=i;
			break;
		}
	}
	ansx=(xpe-xpe%n)/n+1;
	if(ansx%2==1){
		ansy=ansx*n-xpe-1;
	}
	else ansy=xpe-(ansx-1)*n+1;
	cout<<ansx<<' '<<ansy;
	return 0;
}