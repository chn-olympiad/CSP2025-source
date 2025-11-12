#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k,a[200007];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) k=a[i];
	}
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			int j=n*m-i;
			//cout<<i<<' '<<j<<endl;
			cout<<j/n+1<<' ';
			if(j/n%2) cout<<n-j%n;
			else cout<<j%n+1;
		}
	}
	return 0;
} 
