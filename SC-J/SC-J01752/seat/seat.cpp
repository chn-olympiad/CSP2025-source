#include<bits/stdc++.h>
using namespace std;
int a[250],n,m,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>=a[1])cnt++;
	}
	if(cnt%n==0){
		int x=cnt/n;
		if(x%2==0)cout<<x<<" 1";
		else cout<<x<<" "<<n;
	}
	else{
		int x=cnt/n+1;
		if(x%2==0)cout<<x<<" "<<n-cnt%n+1;
		else cout<<x<<" "<<cnt%n;
	}
	return 0;
}
