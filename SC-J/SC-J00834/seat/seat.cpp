#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,aR,aI;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>aR;
	for(int i=2;i<=n*m;i++){
		cin>>aI;
		if(aI>aR)cnt++;
	}
	cout<<cnt/n+1<<" ";
	if((cnt/n)%2==0)cout<<cnt%n+1;
	else cout<<n-cnt%n;
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92

*/