#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],d;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int b=n*m;
	for(int i=1;i<=b;i++) cin>>a[i];
	int c=a[1];
	sort(a+1,a+b+1);
	for(int i=1;i<=b;i++){
		if(a[i]==c) d=b-i+1;
	}
	cout<<d/n+1<<" ";
	if((d/n+1)%2==1) cout<<d%n;
	else cout<<m-d%n+1;
	return 0;
}
