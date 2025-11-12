#include<bits/stdc++.h>
#define ll long long
ll m,n,i,r;
ll a[305];
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++){
			cin>>a[i];
	}
	int r=a[1],ri;
	sort(a+1,a+1+m*n,greater<int>());
	for(int i=1; i<=m*n; i++){
		if(a[i]==r){
			ri=i;
		}
	}
	int l=ceil(ri*1.0/m);
	int h=ri-(l-1)*m;
	if(l%2==1){
		cout<<l<<" "<<h;
	}else{
		cout<<l<<" "<<n-h+1;
	}
	return 0;
}
