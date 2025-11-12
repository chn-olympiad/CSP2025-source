#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=15;

bool cop(int a,int b){
	return a>b;
}
int n,m;
int a[N*N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int x=a[1],ip=0;
	sort(a+1,a+1+n*m,cop);
	for(int i=1;i<=n*m;i++)
		if(a[i]==x){
			ip=i;
			break;
		}
	
	int c=ip/m,r=0;
	if(ip%m!=0)c++;
	if(c%2==0){
		if(ip%n==0)r=1;
		else r=n-ip%n+1;
	}else {
		if(ip%n==0)r=n;
		else r=ip%n;
	}
	cout<<c<<' '<<r;
	
	return 0;
}
