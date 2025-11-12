#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[110];
int r,c;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	
	int x=0;
	for(int i=1;i<=n*m;++i){
		if(a[i]==t){
			x=i;break;
		}
	}
	
	c=(x-1)/n+1;
	
	int h=x%n;
	if(h==0)h=n;
	if(c%2==1)r=h;
	else r=n-h+1;
	cout<<c<<" "<<r;
	
	
	return 0;
}
