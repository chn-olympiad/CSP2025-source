#include <bits/stdc++.h>
using namespace std;
int n,m,a[120],b,c,d,e;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			c=n*m-i+1;
			break;
		}
	}
	d=c/n;
	e=c%n;
	if(e==0)e=n;
	else d++;
	if(d%2==1)cout<<d<<" "<<e;
	else cout<<d<<" "<<n-e+1;
	return 0;
}
