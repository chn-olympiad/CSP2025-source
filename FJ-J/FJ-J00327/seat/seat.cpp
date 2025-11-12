#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			c++;
		}
	}
	int h=c/n;
	if(c%n){
		h++;
	}
	cout<<h<<' ';
	int l=c%n;
	if(!l){
		l=n;
	}
	if(h%2){
		cout<<l<<endl;
	}
	else{
		cout<<n-l+1<<endl;
	}
	return 0;
}

