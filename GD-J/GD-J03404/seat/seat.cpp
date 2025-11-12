#include<bits/stdc++.h>
using namespace std;
int a[101],n,m,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int bb;
		cin>>bb;
		a[bb]++;
		if(i==1){
			a[0]=bb;
		}
	}
	for(int i=100;i>=a[0];i--){
		cnt+=a[i];
	}
	int d=cnt/n,e=cnt%n;
	if(d&1){
		if(!e){
			cout<<d<<' '<<n;
		}else{
			cout<<d+1<<' '<<n-e+1;
		}
	}else{
		if(!e){
			cout<<d<<' '<<1;
		}else{
			cout<<d+1<<' '<<e;
		}
	}
	return 0;
}
