#include<bits/stdc++.h>
using namespace std;
int n,m,p=1,s,l,h,g;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=2;i<=n*m;i++){
		cin>>g;
		if(g>s) p++;
	}
	l=(p-1)/n; 
	h=p-l*n;
	if(l%2) h=n-h+1;
	cout<<l+1<<' '<<h;
	return 0;
}