#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt,l,h;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){cin>>a[i];cnt+=(a[i]>=a[1]);}
	l=cnt/n+(cnt%n?1:0);
	if(l&1)h=(cnt%n?cnt%n:n);
	else h=(cnt%n?n-cnt%n+1:1);
	cout<<l<<' '<<h;
	return 0;
}