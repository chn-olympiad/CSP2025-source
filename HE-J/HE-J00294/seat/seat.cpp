#include <bits/stdc++.h>
using namespace std;
const int N=15;
int a[200];
int n,m,r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	r=a[1];
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+1+n*m,cmp);
	int pos=0,x=0,y=0;
	for(int i=1;i<=n*m;i++)if(a[i]==r)pos=i;
	y=(pos+n-1)/n;//lie
	if(y%2==1) x=pos%n!=0?pos%n:n;
	else x=(n-(pos%n)+1)>n?1:n-(pos%n)+1;
//	for(int i=1;i<=n*m;i++)cout<<a[i]<<" ";
//	puts("");
	cout<<y<<" "<<x;
	return 0;
}
/*
5 5
13 25 2 3 4
5 23 7 8 9
10 11 12 20 14
15 6 17 18 19 
21 16 22 1 24
*/
