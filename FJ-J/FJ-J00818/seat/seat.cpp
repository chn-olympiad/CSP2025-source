#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,grade,othergrade,wz=1;
	cin>>n>>m>>grade;
	for(int i=2;i<=n*m;i++){
		cin>>othergrade;
		if(othergrade>=grade) wz+=1;
	}
	int x=(wz-wz%n)/n+1,y=wz%n;
	if(y==0) y=n,x--;
	if(x%2==1) cout<<x<<' '<<y;
	else cout<<x<<' '<<n-y+1;
	return 0;
}
