#include<bits/stdc++.h>
using namespace std;
int n,m,v,a,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>v;
	for(int i=1;i<n*m;i++)cin>>a,c+=a>v;
	cout<<(c/n+1)<<' ';
	if((c/n)&1)cout<<(n-c%n);
	else cout<<(c%n+1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
