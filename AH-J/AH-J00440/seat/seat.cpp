#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
typedef long long ll;
ll n,m,a[105],id;
bool cmp(const ll &x,const ll &y){
	return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	id=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==id){
			id=i;
			break;
		}
	}
	ll h=(id+n-1)/n;
	cout<<h<<' ';
	id=id%n;
	if(h%2==1){
		if(id==0){
			cout<<n;
		}
		else{
			cout<<id;
		}
	}
	else{
		if(id==0){
			cout<<1;
		}
		else{
			cout<<n+1-id;
		}
	}
    return 0;
}
