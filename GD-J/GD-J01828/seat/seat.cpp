#include<bits/stdc++.h>
using namespace std;
const int maxn=1e2+10;
long long n,m,a[maxn],ti,t1,x,y;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)    cin>>a[i];
	t1=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(long long i=1;i<=n*m;i++){
		if(a[i]==t1){
			ti=i;
			break;
		}
	}
	y=ti/n+1;
	if(ti%n==0)    y--;
	if(ti%(2*n)<=n&&ti%(2*n)!=0)    x=ti%n;
	else    x=n-ti%n+1;
	if(x==0)    x=n;
	cout<<y<<" "<<x;
	return 0;
}
