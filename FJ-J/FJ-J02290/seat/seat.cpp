#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m;
struct hh{
	int sum,i;
	int x,y;
}a[10100];
bool cmp(hh x,hh y){
	return x.sum>y.sum;
}

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].sum;
		a[i].i=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=0;
	int o=1;
	
	
	for(int i=1;i<=n*m;i++){
		y+=o;
		if(y>n){
			y=n;
			o=-1;
			x++;
		}
		else if(y<1){
			y=1;
			o=1;
			x++;
		}
		if(a[i].i==1){
			cout<<x<<" "<<y;
			break;
		}
	}
	
	return 0;
}
