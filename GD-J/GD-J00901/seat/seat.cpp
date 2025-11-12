#include<bits/stdc++.h>
using namespace std;
int n,m,k,o;
int cnt=0;
int main(){
	freopen("seat.in",r,stdin);
	freopen("seat.out",w,stdout);
	cin>>n>>m;
	cin>>k;
	for(int i=1;i<=n*m-1;i++){
		cin>>o;
		if (k<o) cnt++;
	}
	int x=cnt/n,y=cnt%n;
	if (x%2==0) cout<<x+1<<" "<<y+1;
	else cout<<x+1<<" "<<n-y;
	return 0;
}

