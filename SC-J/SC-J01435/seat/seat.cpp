#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	return x>y;
}
long long n,m,c,r,a[1000],p,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			p=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(long long i=1;i<=1000;i++){
		if(a[i]==p){
			cnt=i;
			break;
		}
	}
	c=cnt/n;
	if(cnt%n!=0){
		c++;
	}
	if(c%2==0){
		r=n-cnt%n+1;
	}
	else{
		r=cnt%n;
		if(r==0){
			r=n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}