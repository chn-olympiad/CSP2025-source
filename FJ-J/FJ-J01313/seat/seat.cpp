#include<bits/stdc++.h>
using namespace std;
int n,m,a[10001],k=1,l,h;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	for(int i=2;i<=n*m;i++)
		if(a[1]<a[i])
			k++;
	if(k%n!=0)
		l=k/n+1;
	else
		l=k/n;
	if(l%2!=0)
		h=k-n*(l-1);
	else
		h=n*l-k+1;
	cout<<l<<" "<<h;
	return 0;
}
