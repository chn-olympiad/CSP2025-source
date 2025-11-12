#include<bits/stdc++.h>
using namespace std;
int n,m,a[150],b,c=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>b;
	for(int i=1;i<=n*m-1;i++){
		cin>>a[i];
		if(a[i]>b) c++;
	}
	int x=(c+n-1)/n,y=c-x*n+n;
	if(x%2==0) cout<<x<<" "<<y-n+1;
	else cout<<x<<" "<<y;
	return 0;
} 
