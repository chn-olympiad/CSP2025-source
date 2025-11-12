#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int a[N],n,m,x,p;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	x=a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)if(a[i]==x)p=i-1;
	int l=p/n+1;
	cout<<l<<' ';
	if(l%2==1){
		cout<<1+p%n;
	}
	else{
		cout<<n-p%n;
	}
}
