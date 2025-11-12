#include<bits/stdc++.h>
#include<string>
using namespace std;
int a[105]= {0},n,m,i;
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for( i=0; i<n*m; i++)cin>>a[i];
	int b=a[0],i=0;
	sort(a,n*m+a,cmp);
	while(b!=a[i])i++;
	i++;
	int o=i/n,p=i%n;
	if(o%2==0) {
		if(p)cout<<o+1<<" "<<p;
		else cout<<o<<" "<<1;
	} else {
		if(p)cout<<o+1<<" "<<n-p+1;
		else cout<<o<<" "<<n;
	}
	return 0;
}
