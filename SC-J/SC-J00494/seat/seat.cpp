#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],k,c,r;
bool cmp(int p1,int p2){
	return p1>p2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			k=i;
			break;
		}
	}
	c=k/n+1;
	if(k%n==0){
		c=k/n;
	}
	r=k%n;
	if(r==0)r=n;
	if(c%2==0){
		r=n-(r-1);
	}
	cout<<c<<' '<<r;
	return 0;
}