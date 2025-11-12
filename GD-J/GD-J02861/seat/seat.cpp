#include<bits/stdc++.h>
using namespace std;
long long n,m,xm,xm_w;
int a[100100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	xm=a[1];
	sort(a,a+n*m+1);
	int o=0;
	for(int i=n*m;i>0;i--){
		o++;
		if(a[i]==xm){
			xm_w=o;
		}
	}
	if(((xm_w/n))%2==0){
		cout<<((xm_w/n)+1)<<' '<<(xm_w%n);
	}else{//       n                m
		cout<<((xm_w/n)+1)<<' '<<n-(xm_w%n)+1;	
	}
	return 0;
}
