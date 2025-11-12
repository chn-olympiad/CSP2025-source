#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,b,c,d,r;
	cin>>n>>m;
	long long a[1000];
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(long long i=1;i<=n*m;i++){
		if(a[i]==b){
			c=i;
			break;
		}
	}
	d=c/n;
	r=c%n;
	if(r==0){
		cout<<d<<" ";
		if(d%2==1){
			cout<<n;
		}
		else{
			cout<<1;
		}
	}
	if(r!=0){
		d=d+1;
		cout<<d<<" ";
		if(d%2==1){
			cout<<r;
		}
		else{
			cout<<n-r+1;
		}
	}
	return 0;
}
