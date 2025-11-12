#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,m,b[110],R,cnt,c,r;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
		if(i==1)
		R=b[i];
	}
	sort(b+1,b+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[i]!=R){
			cnt++;
		}else{
			cnt++;
			break;
		}
	}
	c=ceil(cnt*1.0/n);
	cout<<c<<" ";
	if(c%2==1){
		if(cnt%n==0)cout<<n;
		else cout<<cnt%n;
	}else if(c%2==0){
		if(cnt%n==0)cout<<1;
		else cout<<n+1-cnt%n;
	}
	return 0;
}
