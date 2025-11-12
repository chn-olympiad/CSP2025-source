#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t,c,r;
	cin>>n>>m;
	int a[105];
	cin>>t;
	a[1]=t;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			c=(i-1)/n+1;`
			if(c%2!=0)r=(i-1)%n+1;
			else r=n-(i-1)%n;
			cout<<c<<" "<<r;
		}
	}
}
