#include<bits/stdc++.h>
using namespace std;
int n,m,c,t,l,h,s=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>c;
	for(int i=1;i<n*m;i++){
		cin>>t;
		if(t>c)s++;
	}
	l=(s-1)/n+1;
	h=l*n-s+1;
	if(l%2==1)h=n-h+1;
	cout<<l<<' '<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
