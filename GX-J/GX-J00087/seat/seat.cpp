#include<bits/stdc++.h>
using namespace std;
int n,m,a[100],p=0,set=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int mi=a[1];
	for(int i=2;i<=n*m;i++){
		if(a[i]>mi){
			p++;
		}
	}
	if(((p+1)/n+1)%2==0){
		cout<<(p+1)/m+1<<" "<<n-(p%n);
	}else{
	    cout<<(p+1)/m+1<<" "<<p%n+1;
	}
	return 0;
}
