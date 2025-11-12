#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],x,y=1,c,cnt;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(long long i=1;i<=n*m;i++){
		if(cnt%2==0){
			x++;
		}
		else x--;
		if(x>n){
			cnt++;
			x=n;
			y++;
		}
		else if(x<1){
			cnt++;
			x=1;
			y++;
		}
		if(a[i]==c){
			cout<<y<<' '<<x;
			return 0;
		}
	}
	return 0;
}
