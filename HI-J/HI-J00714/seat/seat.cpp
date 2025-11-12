#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+10][m+10],nm[n*m+10],r;
	cin>>r;
	nm[1]=r;
	for(int i=2;i<=n*m;i++){
		cin>>nm[i];
	}
	for(int i=1;i<=n*m-1;i++){
		for(int j=1;j<=n*m-i-1;j++){
			if(nm[j]<nm[j+1]){
				swap(nm[j],nm[j+1]);
			}
		}
	}
	int sa;
	for(int i=1;i<=n*m;i++){
		if(nm[i]==r){
			sa=i;
		} 
	}
	if(sa%n==0){
		if((sa/n)%2==0){
			cout<<sa/n<<" "<<1;
		}
		else{
			cout<<sa/n<<" "<<n;
		}
	}
	else{
		if((sa/n+1)%2==0){
			cout<<sa/n+1<<" "<<n-sa%n+1;
		}
		else{
			cout<<sa/n+1<<" "<<sa%n;
		}
	}
	return 0;
}

