#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000005],cnt,x,y;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			cnt=a[i];
		}
	}
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]!=cnt){
			continue;
		}
		int l;
		if(i%n==0){
			l=i/n;
		}
		else l=i/n+1;
		if(l%2==1){
			y=i%n;
		}
		else y=n-i%n+1;
		if(y==0)y=n;
		if(y==n+1)y=1;
		x=l;
	}
	cout<<x<<" "<<y;
	return 0;
}
