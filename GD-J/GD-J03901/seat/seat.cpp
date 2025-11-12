#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 105;
int n,m,a[N],res,x,y,k;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i<=n*m; i++){
		cin>>a[i];
	}
	res = a[1];
	sort(a+1,a+n*m+1,cmp);
	x=1,y=1,k=1;
	for(int i = 1; i<=n*m; i++){
		if(a[i] == res){
			cout<<x<<" "<<y<<endl;
			break;
		}
		y += k;
//		cout<<x<<" "<<y<<" "<<i<<endl;
		if(y>n || y<1) y-=k,x++,k=0-k;
	}
	return 0;
}
