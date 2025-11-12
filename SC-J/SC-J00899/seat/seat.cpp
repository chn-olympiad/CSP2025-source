#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct b{
	int price,num;
}a[105];
bool cmp(b x,b y){
	return x.price>y.price;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].price;
		a[i].num=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int lo;
	for(int i=1;i<=n*m;i++){
		if(a[i].num==1){
			lo=i;
			break;
		}
	}
	int r=0;
	int c=lo/(2*n);
	c*=2;
	lo%=2*n;
	if(lo==0){
		r=1;
	}
	else{
		c+=1;
		if(lo<=n){
			r=lo;
		}
		else{
			c+=1;
			lo%=n;
			r=n-lo+1;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
