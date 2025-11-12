#include<bits/stdc++.h>
using namespace std;
long long a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,t,m,o,b[1],p;//n是小木棍的总个数，m是多边形的边数，t记录 
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=3;i<=n;i++){
		m=n-i+1;
		o+=m;
		b[1]=i;
		}
	p=b[1];
	cout<<o+p;
	return 0;
} 
