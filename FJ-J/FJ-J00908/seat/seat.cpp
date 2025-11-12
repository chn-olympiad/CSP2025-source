#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=n*m;--i;) cin>>b,c+=(a<b);
	printf("%d %d",c/n+1,c/n%2?n-c%n:c%n+1);
	return 0;
}
