#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],k=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) k++;
	}
	int b=(k+n-1)/n,c=k%n;
	b+=(c==0);
	cout<<b<<" ";
	if(b%2==1) cout<<c+1<<'\n';
	else cout<<n-c<<'\n';
	return 0;
}
