#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int index=0;
	int k=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[++index];
			if(a[index]>a[1]){
				k++;
			}
		}
	}
	cout<<((k+n-1)/n)<<" ";
	if(((k+n-1)/n)%2==1){
		if(k%n==0){
			cout<<n;
		}else{
			cout<<k%n;
		}
	}else{
		if(k%n==0){
			cout<<1;
		}else{
			cout<<n-(k%n)+1;
		}
	}
	return 0;
}
/*
2 2 97 100 99 98	2 1
2 2 98 100 99 97	2 2
2 2 99 97 100 98	1 2
2 2 100 97 99 98	1 1
*/ 
