#include<bits/stdc++.h>
using namespace std;
int n,m,R,r,c,s,a[310];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)	scanf("%d",&a[i]);
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)	if(a[i]==R)	s=i;
	r=s%(n*2);
	if(r>n){
		r-=n;
		r=n-r+1;
	}
	if(s%n==0)	c=s/n;
	else	c=s/n+1;
	cout<<c<<" "<<r;
	return 0;
}
