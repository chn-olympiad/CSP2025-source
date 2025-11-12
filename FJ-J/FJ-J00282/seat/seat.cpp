#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,a[1005],cnt,c,f;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	for(int i=2;i<=n*m;i++)if(a[i]>a[1])cnt++;
	int c=cnt/n+1;
	if(c&1)f=cnt%n+1;
	else f=n-cnt%n;
	cout<<c<<" "<<f;
	return 0;
}
