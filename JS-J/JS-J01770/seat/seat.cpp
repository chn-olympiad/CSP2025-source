#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[1010],b[1010];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int g=b[1],k,l,h;
	sort(b+1,b+n*m+1);
	for(int i=1;i<=n*m;i++) a[i]=b[n*m-i+1];
	for(int i=1;i<=n*m;i++)if(a[i]==g) k=i;
	l=ceil(double(k)/double(n));
	if(l%2!=0) h=(k-1)%n+1;
	else h=n-(k-1)%n;
	cout<<l<<" "<<h;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
