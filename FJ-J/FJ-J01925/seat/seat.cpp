//seat
#include <bits/stdc++.h>
using namespace std;
int a[122],b[11][11];
int main(){
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1],p=0;
	sort(a+1,a+n*m+1);
	for (int i=n*m;i>=1;i--){
		p++;
		if (a[i]==x){
			break;
		}
	}
	int l,h;
	if (p%n==0){
		l=p/n;
	}
	else{
		l=p/n+1;
	}
	if (l%2==1){
		h=p%n;
		if (p%n==0){
			h=n;
		}
	}
	else{
		h=n+1-p%n;
		if (p%n==0){
			h=1;
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
