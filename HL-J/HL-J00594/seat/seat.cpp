#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m,a[105];
void bubble(){
	for(int i=n*m; i>1; i--){
		for(int j=1; j<i; j++){
			if(a[j]<a[j+1]) swap(a[j],a[j+1]);
		}
	}
}
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++){
		cin>>a[i];
	}
	int i=0,k=a[1];
	bubble();
	for(i=1; i<=n*m; i++){
		if(a[i]==k) break;
	}
	if(i%n==0){
		cout<<i/n<<" ";
		k=i/n;
		if(k%2==0) cout<<1;
		else cout<<n;
	}
	else{
		 cout<<i/n+1<<" ";
		 k=i/n+1;
		 if(k%2==0) cout<< n-(i%n)+1;
		 else cout<<i%n;
	}
	return 0;
}
