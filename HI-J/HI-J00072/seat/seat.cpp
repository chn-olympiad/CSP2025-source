#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	int n,m;
	cin>>n>>m;
	int a[105];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a,a+n*m+1);
	int j=1;
	for( ;j<=n*m;j++){
		if(r==a[j]) {
	 		break;
		}	
	}
	j=n*m-j;
	int c=0;
	if(j%m==0) c=j/m;
	else c=j/m+1;
	if(c%2==1){
		if(j%m==0) cout<<c<<" "<<"0";
		else cout<<c<<" "<<j-m*c;
		return 0;
	}
	else {
		if(j%m==0) cout<<c<<" "<<"0";
		else cout<<c<<" "<<n-j%m+1;
	}	
	
	return 0;
} 
