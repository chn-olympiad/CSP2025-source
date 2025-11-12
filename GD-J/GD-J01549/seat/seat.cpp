#include<bits/stdc++.h>
using namespace std;
int main(){
	short n,m,r,b=0;
	cin>>n>>m;
	short a[n*m];
	for(short i=0;i<n*m;i++){
		cin>>a[i];
	}
	r=a[0];
	sort(a,a+n*m+1);
	for(short i=n*m;i>0;i--){
		if(a[i]==r){
			if(m==1)  cout<<1<<' '<<b+1;
			else if(m==2){
				if(b<n)  cout<<1<<' '<<b+1;
				else cout<<2<<' '<<n+n-b;
			}
			else  cout<<1<<' '<<b+1;
		}
		b++;
	}
	return 0;
}
