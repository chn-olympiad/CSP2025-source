#include <bits/stdc++.h>
using namespace std;
int n,m,x;
const int N=11;
int a[N];
int s;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x) {
			s=i;
			break;
		}
	}
	int c=(s+m-1)/m;
	int r;
	if(c%2==1){
		r=s%n;
	}
	else{
		r=n-s%n+1;
	}
	if(r==0) r=n;
	cout<<c<<' '<<r<<endl;
	return 0;
}

