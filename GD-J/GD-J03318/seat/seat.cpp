#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sort stable_sort
int n,m,a[105],cheng,ind,x,y;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;cin>>a[1];cheng=a[1];
	for(int i=2;i<=n*m;i++) cin>>a[i];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==cheng){
			ind=i;
			break;
		}
	}x=ceil(1.0*ind/n);
	if(x&1){
		y=ind-(x-1)*n;
	}else y=n-(ind-(x-1)*n)+1;
	cout<<x<<' '<<y;
	return 0;
}
