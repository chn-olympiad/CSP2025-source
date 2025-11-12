#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=105;
int n,m,a[N],R,k;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)if(a[i]==R)k=i;
	int l=(k+n-1)/n;
	cout<<l<<' '<<(l&1?(k%n==0?n:k%n):(k%n==0?1:n-k%n+1));
}