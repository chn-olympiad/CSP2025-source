#include<bits/stdc++.h>
using namespace std;
const int N=120;
int n,m,a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int tt=a[1],op;
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)if(a[i]==tt){op=n*m-i+1;break;}
	int l=(op-1)/m+1;
	cout<<l<<" "<<(l%2?((op-1)%m+1):m-((op-1)%m+1)+1)<<'\n';
	return 0;
} 
