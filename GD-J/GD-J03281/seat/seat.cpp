#include<bits/stdc++.h>
using namespace std;
int n,m,k,aa,b;
int a[110];
int main(){
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	cin>>n>>m>>a[1];
	k=1;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])k++;
	}
	if(k%n==0)aa=k/n;
	else aa=(k-k%n)/n+1;
	if(k%2==1)
		b=(k-1)%n+1;
	else
		b=m-(k-1)%n;
	cout<<aa<<" "<<b;
	return 0;
}
