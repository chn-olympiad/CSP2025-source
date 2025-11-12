#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],w;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int nm=n*m;
	for(int i=0;i<nm;i++) cin>>a[i];
	int r=a[0];
	sort(a,a+nm);
	for(int i=0;i<nm;i++){
		if(a[i]==r) w=nm-i;
	}
	int rr=w%n;
	if(rr==0){
		int c=w/n;
		if(c%2==1) cout<<c<<" "<<n;
		else cout<<c<<" "<<1;
	}else{
		int c=w/n+1;
		if(c%2==1) cout<<c<<" "<<rr;
		else cout<<c<<" "<<n-rr+1;
	}
	return 0;
}