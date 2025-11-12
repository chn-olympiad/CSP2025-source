#include <bits/stdc++.h>
using namespace std;
int n,m;
int x,r,num=1;
int h,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	for(int i=2;i<=n*m;i++){
		cin>>x;
		if(x>r) num++;
	}
	h=num/n;
	if(num%n!=0) h++;
	l=num%n;
	if(l==0) l=n;
	if(h%2==0) l=n-l+1;
	cout<<h<<' '<<l;
	return 0;
}

