#include <bits/stdc++.h>
using namespace std;
int a[1005],n,m,s,p;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=(n*m);i++)
		cin>>a[i];
	s = a[1];
	sort(a+1,a+n*m+1);
	for(int i = (n*m);i>=1;i--)
		if(s == a[i]){
			p = (n*m)-i+1;
			break;
		}
	if(p/n%2 == 0){
		if(p%n!=0)cout <<p/n+1<<' '<<p%n;
		else cout <<p/n<<' '<<1;
	}	
	else {
		if(p%n!=0)cout <<p/n+1<<' '<<n-p%n+1;
		else cout <<p/n<<' '<<n;
	}
	return 0;
}
