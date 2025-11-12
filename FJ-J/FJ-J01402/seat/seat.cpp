#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],x=1,ls,ps,p;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])x++;
	}
    if(x%n==0)ls=x/n;
    else ls=x/n+1;
    ps=x%n;
    if(ps==0)ps=n;
    if(ls%2==0){
    	p=n-ps+1;
	}
	else p=ps;
	cout<<p<<" "<<ls;
	return 0;
}