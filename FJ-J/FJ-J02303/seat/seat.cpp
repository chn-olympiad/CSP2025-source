#include <bits/stdc++.h>
using namespace std;
short n,m;
int b,k,cnt,c,r;
int main(){
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	cin>>n>>m>>b;
	for(int i=2;i<=n*m;i++){
		cin>>k;
		if(k>b) cnt++;
	}
	cnt++;
	if(cnt%n==0)
		c=(cnt/n);
	else
		c=(cnt/n+1);
	if(c%2==1){
		if(cnt%n==0)r=n;
		else r=cnt%n;
	}
	else{
		r=(n+1-cnt%n);
	}
	cout<<c<<' '<<r;
	return 0;
}
