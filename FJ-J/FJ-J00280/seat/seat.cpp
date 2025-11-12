#include<bits/stdc++.h>
using namespace std;
int n,m,rs,tot,x,hang,lie;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>rs;
	for(int i=2;i<=n*m;i++){
		cin>>x;
		if(x>rs) tot++;
	}
	tot+=1;
	lie=ceil(1.0*tot/n);
	hang=tot-(lie-1)*n;
	if(lie%2==0) hang=n-hang+1;
	cout<<lie<<' '<<hang;
	return 0;
}
