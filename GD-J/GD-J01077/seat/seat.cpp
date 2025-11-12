#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int r=m*n;
	int a[r+10];
	for(int i=1;i<=r;i++) cin>>a[i];
	int cnt;
	for(int i=2;i<=r;i++){
		if(a[i]>a[1]) cnt++;
	}
	int b=cnt/n,c=cnt%n;
	if(b%2==1) cout<<b+1<<" "<<n-c;
	else cout<<b+1<<" "<<n;
	return 0;
}
