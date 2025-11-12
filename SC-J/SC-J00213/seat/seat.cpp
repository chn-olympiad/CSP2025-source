#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a,k,cnt=1;
	cin>>k;
	for(int i=2;i<=n*m;i++){
		cin>>a;
		if(a>k) cnt++;
	}
	int x=(cnt-1)/n;
	int y=cnt%n;
	if(x%2==0){
		if(y==0) y=n;
		cout<<x+1<<' '<<y;
	}else{
		y=n+1-y;
		if(y==n+1) y=1;
		cout<<x+1<<' '<<y;
	}
	return 0;
}