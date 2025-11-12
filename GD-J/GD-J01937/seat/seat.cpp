#include<bits/stdc++.h>
using namespace std;
int a[200],cnt=1;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i!=1&&a[i]>a[1]) cnt++;
	}
	int lol=ceil(cnt*1.0/n);
	int lmao;
	if(cnt%n==0) lmao=n;
	else lmao=cnt%n;
	if(lol%2==0) lmao=n-lmao+1;
	cout<<lol<<" "<<lmao; 
	return 0;
}
/*
waste too much time such an ez question:( 8:57
*/ 
