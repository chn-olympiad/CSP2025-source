#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int tem=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==tem){
			tem=n*m-i+1;
			break;
		}
	}
	if((tem%n==0?tem/n:tem/n+1)%2){
		cout<<(tem%n==0?tem/n:tem/n+1)<<" "<<(tem%n==0?tem:tem%n);
	}else{
		cout<<(tem%n==0?tem/n:tem/n+1)<<" "<<n-(tem%n==0?0:tem%n-1);
	}
	return 0;
}
