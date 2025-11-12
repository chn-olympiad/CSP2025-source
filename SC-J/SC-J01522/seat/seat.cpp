#include<bits/stdc++.h>
using namespace std;
int m,n,ranking;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	int num=n*m;
	for(int i=1;i<=num;i++){
		cin>>a[i];
	}
	int rgrade=a[1];
	sort(a+1,a+num+1);
	for(int i=num;i>=1;i--){
		if(a[i]==rgrade){
			ranking=num-i+1;
			break;
		}
	}
	ranking--;
	int c=ranking/n+1;
	cout<<c<<' ';
	int r;
	if(c%2==1){
		r=ranking-(c-1)*n+1;
	}
	else{
		r=n-(ranking-(c-1)*n);
	}
	cout<<r;
	return 0;
}
