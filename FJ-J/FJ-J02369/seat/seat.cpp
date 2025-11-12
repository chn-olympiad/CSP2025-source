#include<bits/stdc++.h>
using namespace std;

int a[105];
int n,m;
int r,c;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int R=a[1];
	
	sort(a+1,a+n*m+1,cmp);
	
	int ip;
	for(int i=1;i<=n*m;i++) if(a[i]==R) ip=i;
	
	if(ip%n==0) c=ip/n;
	else c=ip/n+1;
	
	if((ip/n)%2==0 || ip%n==0 && ip/n%2!=0) {
		r=ip%n;
		if(r==0) r=n;
	}
	else{
		r=ip%n;
		if(r==0) r=n;
		r=n-r+1;
	}
	
	cout<<c<<" "<<r;
	
	return 0;
}
