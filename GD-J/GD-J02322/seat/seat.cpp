#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int c=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==c){
			c=n*m-i+1;
			break;
		}
	}
	int a1=c/n+1,a2;
	if(c%n==0){
		a1--;
	}
	if(a1%2==1){
		a2=c-(a1-1)*n;
	}else{
		a2=n-(c-(a1-1)*n)+1;
	}
	cout<<a1<<" "<<a2;
	return 0;
} 
