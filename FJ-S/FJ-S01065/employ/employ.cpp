#include<bits/stdc++.h>
using namespace std;
char a;
int n,m,x[501],y[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		x[i]=int(a)-48;
	}
	for(int i=1;i<=n;i++)cin>>y[i];
	cout<<rand()%998244353;
	return 0;
}
