#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])cnt++;
	}int x=(cnt+n-1)/n,y;
	y=cnt-(x-1)*n;
	if(x%2==0)y=n-y+1;
	cout<<x<<" "<<y;
	return 0;
} 