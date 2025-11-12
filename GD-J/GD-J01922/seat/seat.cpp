#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],cnt=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1])cnt++;
	}
	int x=cnt/n+1,y=cnt%n+1;
	if(x%2==0)y=n-y+1;
	cout<<x<<" "<<y;
	return 0;
}
