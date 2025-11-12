#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;int s=n*m,g=1;
	for(int i=1;i<=s;i++){
		cin>>a[i];
		if(a[i]>a[1])g++;
	}
	int i=g/n+1,j=g%n;
	i%2==0?cout<<i<<" "<<n+1-j:cout<<i<<" "<<j;
	return 0;
}

