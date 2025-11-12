#include <bits/stdc++.h>
using namespace std;
int n,m,b;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	if(b==1){
		cout<<m<<" "<<n;
	}else if(b==m*n||b==100){
		cout<<"1"<<" "<<"1";
	}else{
		int ant=1;
		for(int i=2;i<=n*m;i++){
			if(a[1]<a[i]){
				ant++;
			}
		}
		if(n==1){
			cout<<"1"<<" "<<ant;
		}else if(m==1){
			cout<<ant<<" "<<"1";
		}else{
			cout<<floor(ant/n)<<" "<<ant%n+1;
		}
	}
	return 0;
}
