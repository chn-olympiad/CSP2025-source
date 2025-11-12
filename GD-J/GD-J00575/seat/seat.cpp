#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	a[0]=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==a[0]){
			const int x=(i-1)/n+1,y=(i%n==0?n:i%n);
			cout<<x<<' '<<(x&1?y:n-y+1);
			return 0;
		}
	return 0;
}
