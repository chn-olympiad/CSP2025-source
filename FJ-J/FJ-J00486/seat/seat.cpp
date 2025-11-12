#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],cnt; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		cin>>a[i]; 
		if(a[i]>=a[1]) cnt++;
	}
	int c=ceil(cnt*1.0/n);
	cout<<c<<' ';
	if(c%2==1){
		if(cnt%n==0) cout<<n;
		else cout<<cnt%n;
	}
	else{
		if(cnt%n==0) cout<<1;
		else cout<<n-cnt%n+1;
	}
	return 0;
}

