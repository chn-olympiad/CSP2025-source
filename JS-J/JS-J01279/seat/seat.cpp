#include<bits/stdc++.h>
using namespace std;
int n,m,a[100],a1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	a1=a[0];
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++){
		if(a[i]==a1){
			a1=n*m-i;
			break;
		}
	}
	cout<<(a1+m-1)/m<<' ';
	if((a1+m-1)/m%2){
		cout<<(a1%m==0?m:a1%m);
	}
	else{
		cout<<m-(a1%m==0?m:a1%m)+1;
	}
	return 0;
}
