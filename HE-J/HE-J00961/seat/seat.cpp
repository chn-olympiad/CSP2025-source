#include <bits/stdc++.h>
#define ios ios::sync_with_stdio(false),cin.tie(nullptr),cin.tie(nullptr);
using namespace std;

const int N=1e4;
int n,m,a[N],w,id;

bool cmp(int x,int y){
	return x>y;
}

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios;
	cin>>n>>m;
	cin>>a[1];
	w=a[1];
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)	if(a[i]==w)	id=i;
	int y=(id-1)/n+1,x;
	if(y%2==1)	x=(id-1)%n+1;
	else x=n-(id-1)%n;
	cout<<y<<' '<<x;
	return 0;
}
