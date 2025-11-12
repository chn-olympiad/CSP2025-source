#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int cj=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=i;j++){
			if(a[i]>a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	int c;
	for(int i=1;i<=n*m;i++){
		if(a[i]==cj){
			c=i;
		}
	}
	int a1=c/n,a2=c%n;
	if(a1%2==1){
		if(a2==0){
			cout<<a1<<" "<<n;
		}
		else{
			cout<<a1+1<<" "<<n-a2+1;
		}
	}
	else{
		if(a2==0){
			cout<<a1<<" "<<1;
		}
		else{
			cout<<a1+1<<" "<<a2;
		}
	}
	return 0;
} 
