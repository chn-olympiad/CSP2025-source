#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[10010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int v=a[1];
	sort(a+1,a+1+n*m);
	int t;
	for(int i=1;i<=n*m;i++){
		if(a[i]==v)t=i;
	}
	int c,r;
	if(t%n==0)c=t/n;
	else c=t/n+1;
	if(c%2==0)r=t-c*n+n+1;
	else r=n-(t-c*n+n)+1;
	cout<<m-c+1<<" "<<r;
	return 0;
}