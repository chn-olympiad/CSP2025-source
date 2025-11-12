#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=0;
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1]) t++;
	}
	t++;
	if(n==1) cout<<1<<' '<<1;
	else if(m==1) cout<<1<<' '<<t/m;
	if(n==2) cout<<m<<n;
	return 0;
}
