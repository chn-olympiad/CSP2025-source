#include <bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[1];
	int exp=a[1],sn=1;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,greater<int>());
	while(a[sn]!=exp&&sn<=n*m){
		sn++;
	}
	int x=sn/n,y=sn%n;
	if(x%2==0){
		if(y==0) cout<<x<<" "<<1;
		else cout<<x+1<<" "<<y;
	}
	else{
		if(y==0) cout<<x<<" "<<n;
		else cout<<x+1<<" "<<n+1-y;
	}
	return 0;
}