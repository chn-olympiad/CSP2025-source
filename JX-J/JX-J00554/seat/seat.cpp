#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
int a1,j8;
int kkk,d;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==a1){
			kkk=n*m-i+1;
		}
	}
	d=kkk%n;
	if(d==0){
		d=n;
	}
	if(((kkk-1)/n)%2==1){
		cout<<(kkk-1)/n+1<<" "<<n-d+1;
	}
	else if(((kkk-1)/n)%2==0){
		cout<<(kkk-1)/n+1<<" "<<d;
	}
	return 0;
}
