#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x=n*m;
	for(long long i=1;i<=x;i++){
		cin>>a[i];
	}
	if(x==1){
		cout<<"1 1";
		return 0;
	}
	int r=a[1];
	int w=0;
	sort(a+1,a+x+1);
	reverse(a+1,a+x+1);
	for(int i=1;i<=x;i++){
		if(a[i]==r){
			w=i;
			break;
		}
	}
	if(w%n==0){
		int t=w/n;
		if(t%2!=0){
		cout<<t<<" "<<n;
		return 0;
	}
	cout<<t<<" "<<"1";
	return 0;
	}
	else{
		int t=w/n+1;
		if(t%2!=0){
		int y=w%n;
		cout<<t<<" "<<y;
		return 0;
	}
	int y=n-(w%n-1);
	cout<<t<<" "<<y;
	return 0;
	}
} 
