#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+1+n*m);
	int l=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			l=n*m-i+1;
			break;
		}
	}
	int a=0,b=0;
	a=ceil(l*1.0/n);
	b=l%n;
	if(b==0){
		b=n;
	}
	if(!(a%2)){
		b=n-b+1;
	}
	cout<<a<<" "<<b;
	return 0;
}
