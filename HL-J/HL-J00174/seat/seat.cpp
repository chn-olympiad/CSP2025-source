#include<bits/stdc++.h>
using namespace std;
int n,m,x,a[101],tur=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>x;
	for(int i=0;i<n*m-1;i++){
		cin>>a[i];
		if(a[i]>x){
			tur++;
		}
	}
	if(tur%(n*2)>0&&tur%(n*2)<=n){
		cout<<(tur-1)/n+1<<' '<<(tur-1)%n+1;
	}
	else{
		cout<<(tur-1)/n+1<<' '<<n+1-(tur-1)%n-1;
	}
	return 0;
}
