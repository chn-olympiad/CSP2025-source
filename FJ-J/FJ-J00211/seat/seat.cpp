#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],smalla,zw;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int s=n*m;
	for(int i=1;i<=s;i++) cin>>a[i];
	smalla=a[1];
	sort(a+1,a+1+s);
	for(int i=1;i<=s;i++){
		if(a[i]==smalla) zw=s-i+1;
	}
	int lie=(zw%n==0?zw/n:zw/n+1),hang;
	if(lie%2==0) hang=(zw%n==0?1:n-(zw%n)+1);
	else hang=(zw%n==0?n:zw%n);
	cout<<lie<<" "<<hang;
	return 0;
}
