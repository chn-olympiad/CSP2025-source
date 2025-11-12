#include <bits/stdc++.h>
using namespace std;
int a[6000];
int cnt;
void fs(int li,int n,int nl,int nm,int ns){
	if(nl>=3&&ns>2*nm){
		cnt++;
	}
	for(int i=li+1;i<n;i++){
		fs(i,n,nl+1,max(nm,a[i]),ns+a[i]);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	fs(-1,n,0,0,0);
	cout<<cnt%998244353;
	return 0;
}
