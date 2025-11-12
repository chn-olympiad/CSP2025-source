#include <bits/stdc++.h>
using namespace std;

int a[1105];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int cnt=1;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			cnt++;
		}
	}
	int x=cnt/n;
	int t=cnt%n;
	if(t==0){
		if(x%2==0){
			cout<<x<<' '<<"1";
		}
		else{
			cout<<x<<' '<<n;
		}
	}
	else{
		if(x%2==0){
			cout<<x+1<<' '<<t;
		}
		else{
			cout<<x+1<<' '<<n-t+1;
		}
	}
	
	return 0;
} 
