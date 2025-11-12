#include<bits/stdc++.h>
using namespace std;
int n,m,x,t[1001],r,s,ss,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>x;
			t[x]++;
			if(i==1&&j==1) r=x;
		}
	}
	for(int i=100;i>=1;i--){
		if(t[i]) s++;
		if(i==r) break;
	}
	cnt=s/(2*n);
	ss=s%(2*n);
	if(ss==0){
		cout<<cnt*2+2<<" "<<1;
		return 0;
	}
	if(ss<=n) cout<<cnt*2+1<<" "<<ss;
	else cout<<cnt*2+2<<" "<<2*n+1-ss;
	return 0;
}
