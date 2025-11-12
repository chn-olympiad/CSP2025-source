#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int a,s=1,ou;
	cin>>a;
	for(int i=1;i<n*m;i++){
		cin>>ou;
		if(ou>a)s++;
	}
	cout<<(s-1)/n+1<<' ';
	if(((s-1)/n)%2==0)cout<<(s-1)%n+1;
	else cout<<n-((s-1)%n);
	return 0;
}
//he yi wei
