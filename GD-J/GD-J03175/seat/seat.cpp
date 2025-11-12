#include<bits/stdc++.h>
#define int long long
#define l first
#define r second
using namespace std;
int n,m,a[1005],x;
pair<int,int>seats;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>a[1];x=a[1];
	for(int i=2;i<=n*m;i++)
		cin>>a[i];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(x==a[i]){
			if(i%n==0) cout<<i/n,seats.l=i/n;
			else cout<<(i/n)+1,seats.l=(i/n)+1;
			cout<<' ';
			if(i%n==0){
				if(seats.l%2==0)cout<<1;
				else cout<<n;
			} 
			else{
				if(seats.l%2==0)cout<<n-(i%n)+1;
				else cout<<i%n;
			}
		}
	}
	return 0;
}
