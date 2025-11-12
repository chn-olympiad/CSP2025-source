#include<bits/stdc++.h>
using namespace std;
int n,m,a[114],R,pR;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	R=a[1];sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++) if(a[i]==R){pR=i;break;}
	int t=(pR-1)/n+1;
	cout<<t<<' '<<((t%2==1)?(((pR-1)%n)+1):(n-((pR-1)%n)));//;
 }
/*
1 16
13 2 3 4 5 6 7 8 9 10 11 12 1 14 15 16
*/
