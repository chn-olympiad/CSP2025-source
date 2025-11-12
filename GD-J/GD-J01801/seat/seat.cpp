#include<bits/stdc++.h>
using namespace std;
int a[111];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,xr,h=1,l=1;bool p=false;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	xr=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==xr){cout<<l<<" "<<h;return 0;
		}
		if(!p)
		h++;
		if(p)
		h--;
		if(h>n&&!p){
			h=n;l++;p=true;
		}
		else if(h<1&&p){
			h=1;l++;p=false;
		}
	}
	return 0;
}
