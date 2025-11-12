#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s,x;
	cin>>s;
	int cnt=0;
	for(int i=2;i<=n*m;i++){
		cin>>x;
		if(x>s) cnt++;
	}
	int a=cnt/n;
	int b=cnt%n;
	cout<<a+1<<" ";
	if(a%2==0) cout<<b+1;
	else cout<<n-b;
}
