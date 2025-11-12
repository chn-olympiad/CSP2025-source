#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],s,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+1+(n*m));
	for(int i=n*m;i>=1;i--){
		if(a[i]==s){
			l=n*m-i+1;
			break;
		}
	}
	if(l%m==0){
		cout<<l/m<<" ";
		if((l/m)%2==1)cout<<m;
		else cout<<1;
	}
	else{
		cout<<(l/m)+1<<" ";
		if((((l/m)+1))%2==1){
			cout<<l%m;
		}
		else{
			cout<<(m+1)-(l%m);
		}
	}
	return 0;
}
