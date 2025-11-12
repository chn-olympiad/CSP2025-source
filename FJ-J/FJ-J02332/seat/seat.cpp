#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x,num,ln,dn;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	x=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==x){
			num=n*m-i+1;
			break;
		}
	}
	ln=(num-1)/n+1;
	if(ln%2==1) dn=(num-1)%n+1;
	else dn=n-(num-1)%n;
	cout<<ln<<" "<<dn<<"\n";
	return 0;
}
