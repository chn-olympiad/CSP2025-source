#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005],x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1,greater<int>());

	for(int i=1;i<=n*m;i++){
		if(x==a[i]){

			int c=(i-1)/n+1;
			cout<<c<<" ";
			if(c%2==1){
				if(i%n==0)cout<<n;
				else cout<<i%n;
			}
			else{
				if(i%n==0)cout<<1;
				else cout<<n-i%n+1;	
			}
		}
	}
	return 0;
}
