#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[114];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int cnt=1;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) cnt++;
	}
	int a=cnt%n,b=cnt/n;
	if(a==0){
		cout<<b<<" ";
		if(b%2==0) cout<<'1';
		else cout<<n;
	}else{
		cout<<b+1<<" ";
		if((b+1)%2==0) cout<<n-a+1;
		else cout<<a;
	}
	return 0;
}

