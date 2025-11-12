#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
int a[n*m];
for(int i=1;i<=n*m;i++){
	cin>>a[i];
	}
int num=a[1];
for(int i=1;i<=n*m;i++){
	for(int j=1;j<=n*m;j++){
		int b=a[i];
		if(a[i]<a[j]){
		a[i]=a[j];
		a[j]=b;
		}
	}
}	
for(int i=1;i<=n*m;i++){
	if(a[i]==num)
	cout<<i%n;
	break;
	}
}
