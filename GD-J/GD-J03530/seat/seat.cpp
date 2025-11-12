#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110],xr;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xr=a[1];
	sort(a+1,a+n*m+1,cmp);
	int px=0;
	for(int i=1;i<=n*m;i++){
		if(xr==a[i]){
			px=i;
			break;
		}
	}
	if(px%n==0){
		cout<<px/n<<" ";
		if((px/n)&1==0)cout<<1;
		else cout<<n;
	}
	else if((px/n)&1==0){
		cout<<px/n+1<<" "<<n-px%n+1;
	}
	else cout<<px/n+1<<" "<<px%n;
	return 0;
}
