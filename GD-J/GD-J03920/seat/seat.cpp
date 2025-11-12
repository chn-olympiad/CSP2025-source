#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int R=a[0];
	sort(a,a+n*m);
	int pr=lower_bound(a,a+n*m,R)-a;
	pr=(n*m)-pr;
//	cout<<pr<<endl;
	int c=(pr-1)/n+1;
	int r=pr%n;
	if(r==0)r=n;
	if(c%2==0)r=n+1-r;
	cout<<c<<" "<<r;
	return 0;
}
