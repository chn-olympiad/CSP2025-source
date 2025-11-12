#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[2000000];

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a0,mc,h,l;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	a0=a[0];
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++){
		if(a[i]==a0){
			mc=n*m-i;
			break;
		}
	}
	h=(mc-1)/n+1;
	if(h%2==1){
		l=(mc-1)%m+1;
	}
	else{
		l=n-((mc-1)%m);
		
	}
	cout<<h<<' '<<l;
	return 0;
}

